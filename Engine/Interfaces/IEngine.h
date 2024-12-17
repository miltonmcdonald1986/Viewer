#pragma once

#include <memory>
#include <string>

#include "DllImpExp.h"

namespace Viewer
{

	class IEngine
	{
	public:
		virtual ~IEngine() = default;
		virtual std::string HelloWorld() const = 0;
		virtual void Render() const = 0;
		virtual void SetBackgroundColor(float r, float g, float b, float a = 1.f) = 0;
	};

	using IEngineSPtr = std::shared_ptr<IEngine>;
	DllImpExp IEngineSPtr CreateEngine();

}
