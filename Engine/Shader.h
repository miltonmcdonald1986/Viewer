#pragma once

namespace Viewer
{

	class Shader
	{
	public:
		~Shader();

		bool CompileFragmentShaderFromSource(const std::filesystem::path& fsPath);
		bool CompileVertexShaderFromSource(const std::filesystem::path& vsPath);
		bool LinkProgram();
		bool Use() const;

	private:
		bool CompileShaderFromSource(GLenum shaderType, const std::filesystem::path& path);
		std::optional<GLuint> CreateShader(GLenum shaderType);
		GLuint* GetShaderData(GLenum shaderType);
		bool SetSourceCode (int shader, const std::string& source);

		GLuint m_FragmentShader = 0;
		GLuint m_VertexShader = 0;
		GLuint m_Program = 0;
		std::string m_Info;
	};

}
