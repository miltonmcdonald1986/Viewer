#pragma once

#include <memory>
#include "IShader.h"
#include "DllImpExp.h"

namespace Viewer
{

	class IEngine
	{
	public:
		virtual ~IEngine() = default;
		virtual auto GetShader(const std::string& name) -> IShaderSPtr const = 0;
		virtual auto HelloTriangle() -> void = 0;
		virtual auto Init() -> bool = 0;
		virtual auto Render() -> void const = 0;
		virtual auto SetBackgroundColor(float r, float g, float b, float a = 1.f) -> void = 0;
	};

	using IEngineSPtr = std::shared_ptr<IEngine>;
	DllImpExp auto CreateEngine() -> IEngineSPtr;

}
