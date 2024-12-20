#pragma once

#include <memory>
#include "DllImpExp.h"

namespace Viewer
{

	class IEngine
	{
	public:
		virtual ~IEngine() = default;
		virtual void HelloTriangle() = 0;
		virtual bool Init() = 0;
		virtual void Render() const = 0;
		virtual void SetBackgroundColor(float r, float g, float b, float a = 1.f) = 0;
	};

	using IEngineSPtr = std::shared_ptr<IEngine>;
	DllImpExp IEngineSPtr CreateEngine();

}
