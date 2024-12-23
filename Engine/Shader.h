#pragma once

#include "IShader.h"
#include "Alias.h"

using ProgramId = GLuint;
using ShaderId = GLuint;
using ShaderIds = std::vector<ShaderId>;

namespace Viewer
{

	enum class ShaderType : size_t
	{
		Fragment,
		Vertex
	};

	using ShaderSources = std::map<ShaderType, Path>;

	class Shader : public IShader
	{
	public:
		Shader(const ShaderSources sources);

		~Shader();

		virtual auto SetUniform(const String& name, const Vec4& value) -> bool const override;
		virtual auto Use() -> bool const override;

	private:
		auto LinkProgram(const ShaderIds& shaders) -> bool;

		bool m_Initialized = false;
		ProgramId m_Program = 0;
		String m_Info;
	};

}
