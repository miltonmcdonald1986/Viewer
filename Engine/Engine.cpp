#include "pch.h"

#include <filesystem>
#include <format>
#include <fstream>
#include <sstream>
#include <vector>

#include "GL/glew.h"

#include "Engine.h"

namespace
{

	std::string GlEnumAsString(GLenum glEnum)
	{
		switch (glEnum)
		{
		case GL_NO_ERROR:
			return "GL_NO_ERROR";
		case GL_INVALID_ENUM:
			return "GL_INVALID_ENUM";
		case GL_INVALID_VALUE:
			return "GL_INVALID_VALUE";
		case GL_INVALID_OPERATION:
			return "GL_INVALID_OPERATION";
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			return "GL_INVALID_FRAMEBUFFER_OPERATION";
		case GL_OUT_OF_MEMORY:
			return "GL_OUT_OF_MEMORY";
		case GL_STACK_UNDERFLOW:
			return "GL_STACK_UNDERFLOW";
		case GL_STACK_OVERFLOW:
			return "GL_STACK_OVERFLOW";
		default:
			return "Unknown enum.";
		}
	}

	GLuint CreateGenericShaderProgram()
	{
		// Source code for a vertex shader.
		const char* vertexShaderSource =
			R"(#version 330 core
layout(location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
})";

		// Create an empty shader object.
		GLuint  idVertexShader = glCreateShader(GL_VERTEX_SHADER);
		if (idVertexShader == 0)
		{
			OutputDebugStringA(std::format("Error (glCreateShader): An error ocurred creating the shader object. glGetError: {}\n", GlEnumAsString(glGetError())).c_str());
			return 0;
		}

		// Set the source code in the newly created vertex shader
		// to the string specified by vertexShaderSource
		glShaderSource(idVertexShader, 1, &vertexShaderSource, NULL);
		auto glError = glGetError();
		if (glError != GL_NO_ERROR)
		{
			OutputDebugStringA(std::format("Error (glShaderSource): An error ocurred replacing the source code in the shader object. glGetError: {}\n", GlEnumAsString(glError)).c_str());
			return 0;
		}

		// Compile the vertex shader
		glCompileShader(idVertexShader);
		glError = glGetError();
		if (glError != GL_NO_ERROR)
		{
			OutputDebugStringA(std::format("Error (glCompileShader): An error ocurred compiling the shader. glGetError: {}\n", GlEnumAsString(glError)).c_str());
			return 0;
		}

		// Check if compilation was successful.
		GLint params;
		glGetShaderiv(idVertexShader, GL_COMPILE_STATUS, &params);

		GLint success = params;
		if (success == GL_FALSE)
		{
			// Something went wrong. Print information.

			// Here params is the number of characters in the information log
			// for the vertex shader including the null termination character.
			glGetShaderiv(idVertexShader, GL_INFO_LOG_LENGTH, &params);

			GLint infoLogLength = params;
			std::string infoLog(infoLogLength, ' ');
			glGetShaderInfoLog(idVertexShader, params, NULL, infoLog.data());

			OutputDebugStringA(std::format("Error (glCompileShader): An error ocurred compiling the shader. InfoLog: {}\n", infoLog).c_str());
			return 0;
		}

		const char* fragmentShaderSource =
			R"(#version 330 core
layout(location = 0) out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
})";

		GLuint idFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		if (idFragmentShader == 0)
		{
			OutputDebugStringA(std::format("Error (glCreateShader): An error ocurred creating the shader object. glGetError: {}\n", GlEnumAsString(glGetError())).c_str());
			return 0;
		}

		glShaderSource(idFragmentShader, 1, &fragmentShaderSource, NULL);
		glError = glGetError();
		if (glError != GL_NO_ERROR)
		{
			OutputDebugStringA(std::format("Error (glShaderSource): An error ocurred replacing the source code in the shader object. glGetError: {}\n", GlEnumAsString(glError)).c_str());
			return 0;
		}

		glCompileShader(idFragmentShader);
		glError = glGetError();
		if (glError != GL_NO_ERROR)
		{
			OutputDebugStringA(std::format("Error (glCompileShader): An error ocurred compiling the shader. glGetError: {}\n", GlEnumAsString(glError)).c_str());
			return 0;
		}

		// Check if compilation was successful.
		glGetShaderiv(idVertexShader, GL_COMPILE_STATUS, &params);
		success = params;
		if (success == GL_FALSE)
		{
			// Something went wrong. Print information.

			// Here params is the number of characters in the information log
			// for the vertex shader including the null termination character.
			glGetShaderiv(idVertexShader, GL_INFO_LOG_LENGTH, &params);

			GLint infoLogLength = params;
			std::string infoLog(infoLogLength, ' ');
			glGetShaderInfoLog(idVertexShader, params, NULL, infoLog.data());

			OutputDebugStringA(std::format("Error (glCompileShader): An error ocurred compiling the shader. InfoLog: {}\n", infoLog).c_str());
			return 0;
		}

		GLuint idShaderProgram = glCreateProgram();
		glAttachShader(idShaderProgram, idVertexShader);
		glAttachShader(idShaderProgram, idFragmentShader);
		glLinkProgram(idShaderProgram);
		glGetProgramiv(idShaderProgram, GL_LINK_STATUS, &params);
		success = params;
		if (success == GL_FALSE)
		{
			// Something went wrong. Print information.

			// Here params is the number of characters in the information log
			// for the vertex shader including the null termination character.
			glGetProgramiv(idShaderProgram, GL_INFO_LOG_LENGTH, &params);

			GLint infoLogLength = params;
			std::string infoLog(infoLogLength, ' ');
			glGetProgramInfoLog(idShaderProgram, params, NULL, infoLog.data());

			OutputDebugStringA(std::format("Error (glLinkProgram): An error ocurred linking the program. InfoLog: {}\n", infoLog).c_str());
			return 0;
		}

		glDeleteShader(idVertexShader);
		glDeleteShader(idFragmentShader);

		return idShaderProgram;
	}
}

class ShaderProgram
{
public:
	~ShaderProgram()
	{
		glDeleteProgram(m_Program);
	}

	bool CompileFragmentShaderFromSource(const std::filesystem::path& fsPath)
	{
		return CompileShaderFromSource(GL_FRAGMENT_SHADER, fsPath);
	}

	bool CompileVertexShaderFromSource(const std::filesystem::path& vsPath)
	{
		return CompileShaderFromSource(GL_VERTEX_SHADER, vsPath);
	}

	bool LinkProgram()
	{
		m_Program = glCreateProgram();
		glAttachShader(m_Program, m_VertexShader);
		glAttachShader(m_Program, m_FragmentShader);
		glLinkProgram(m_Program);
		
		GLint param;
		glGetProgramiv(m_Program, GL_LINK_STATUS, &param);
		if (param == GL_FALSE)
		{
			// Something went wrong. Get the info log.
			glGetProgramiv(m_Program, GL_INFO_LOG_LENGTH, &param);
			m_Info.resize(param);
			glGetProgramInfoLog(m_Program, param, NULL, m_Info.data());
			return false;
		}

		glDetachShader(m_Program, m_VertexShader);
		glDeleteShader(m_VertexShader);

		glDetachShader(m_Program, m_FragmentShader);
		glDeleteShader(m_FragmentShader);

		return true;
	}

	void Use() const
	{
		glUseProgram(m_Program);
	}

private:
	bool CompileShaderFromSource(GLenum shaderType, const std::filesystem::path& path)
	{
		GLuint* shader = nullptr;
		switch (shaderType)
		{
		case GL_FRAGMENT_SHADER:
			shader = &m_VertexShader;
			break;
		case GL_VERTEX_SHADER:
			shader = &m_FragmentShader;
			break;
		default:
			return false;
		}

		// Open the file containing the source code for the vertex shader.
		std::ifstream ifs(path);

		// Read the file in its entirety.
		std::stringstream ss;
		ss << ifs.rdbuf();
		ifs.close();
		std::string sourceStr = ss.str();
		const char* sourceCStr = sourceStr.c_str();

		// Compile the shader.
		*shader = glCreateShader(shaderType);
		glShaderSource(*shader, 1, &sourceCStr, NULL);
		glCompileShader(*shader);

		// Handle any errors
		GLint param;
		glGetShaderiv(*shader, GL_COMPILE_STATUS, &param);
		if (param == GL_FALSE)
		{
			// Something went wrong. Get the info log.
			glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &param);
			m_Info.resize(param);
			glGetShaderInfoLog(*shader, param, NULL, m_Info.data());
			return false;
		}

		return true;
	}
	
	GLuint m_FragmentShader = 0;
	GLuint m_VertexShader = 0;
	GLuint m_Program = 0;
	std::string m_Info;
};

namespace Viewer
{
	Engine::Engine()
	{
	}

	void Engine::HelloTriangle()
	{
		m_HelloTriangle = true;

		float vertices[] = {
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		unsigned int indices[] = {
			0, 1, 3,
			1, 2, 3
		};

		glGenVertexArrays(1, &m_HelloTriangleVAO);
		glBindVertexArray(m_HelloTriangleVAO);

		// Generate a buffer object name.
		GLuint idVBO;
		glGenBuffers(1, &idVBO);

		// Create a buffer object with name VBO, and bind it
		// to the "Vertex Attributes" buffer binding target.
		glBindBuffer(GL_ARRAY_BUFFER, idVBO);

		// Create a new data store for the buffer currently 
		// bound to GL_ARRAY_BUFFER (in this case, VBO).
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		ShaderProgram shader;
		shader.CompileVertexShaderFromSource(R"(..\shaders\minimal.vs)");
		shader.CompileFragmentShaderFromSource(R"(..\shaders\minimal.fs)");
		shader.LinkProgram();
		shader.Use();

		m_IdHelloTriangleShaderProgram = CreateGenericShaderProgram();

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glEnableVertexAttribArray(0);

		glGenBuffers(1, &m_HelloTriangleEBO);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_HelloTriangleEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	bool Engine::Init()
	{
		// Initialize GLEW
		GLenum err = glewInit();
		if (GLEW_OK != err)
			return false;

		return true;
	}

	void Engine::Render() const
	{
		if (m_HelloTriangle)
			RenderHelloTriangle();
		else
			RenderEverything();
	}

	void Engine::SetBackgroundColor(float r, float g, float b, float a)
	{
		m_R = r;
		m_G = g;
		m_B = b;
		m_A = a;
	}

	void Engine::RenderEverything() const
	{
		glClearColor(m_R, m_G, m_B, m_A);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Engine::RenderHelloTriangle() const
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// glUseProgram(m_IdHelloTriangleShaderProgram);
		
		//glBindVertexArray(m_HelloTriangleVAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_HelloTriangleEBO);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}

	IEngineSPtr CreateEngine()
	{
		return std::shared_ptr<IEngine>(new Engine());
	}

}
