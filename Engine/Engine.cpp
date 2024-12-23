#include "pch.h"

#include "Engine.h"

namespace Viewer
{
	Engine::Engine()
	{
#ifdef _DEBUG
		spdlog::flush_every(std::chrono::seconds(3));
#endif
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

		auto shadersDir = std::filesystem::path(SHADERS_DIR);
		m_Shaders["minimal"] = IShaderSPtr(new Shader({
			{ ShaderType::Fragment, shadersDir / "minimal.fs" },
			{ ShaderType::Vertex, shadersDir / "minimal.vs" }
			}));
		m_Shaders["sandbox"] = IShaderSPtr(new Shader({
			{ ShaderType::Fragment, shadersDir / "sandbox.fs" },
			{ ShaderType::Vertex, shadersDir / "sandbox.vs" }
			}));
		
		IShaderSPtr spShader = m_Shaders["sandbox"];
		spShader->Use();
		spShader->SetUniform("ourColor", glm::vec4(0.f, 1.f, 0.f, 1.f));
		


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
