#pragma once

#include <string>
#include "glm/ext/vector_float4.hpp"

namespace Viewer
{

	class IShader
	{
	public:
		virtual ~IShader() = default;

		virtual auto SetUniform(const std::string& name, const glm::vec4& value) -> bool const = 0;
		virtual auto Use() -> bool const = 0;
	};

	using IShaderSPtr = std::shared_ptr<IShader>;

}
