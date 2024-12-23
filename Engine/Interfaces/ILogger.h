#pragma once

#include "DllImpExp.h"

namespace Viewer
{

	enum LogLevel
	{
		Trace,
		Debug,
		Info,
		Warn,
		Error,
		Critical
	};

	class ILogger
	{
	public:
		virtual ~ILogger() = default;

		// Standard log functionality
		virtual void Trace(const std::string& message) const = 0;
		virtual void Debug(const std::string& message) const = 0;
		virtual void Info(const std::string& message) const = 0;
		virtual void Warn(const std::string& message) const = 0;
		virtual void Error(const std::string& message) const = 0;
		virtual void Critical(const std::string& message) const = 0;

		// Specialized logging
		virtual void OpenGLError(GLenum error, const std::string& message = "") const = 0;
	};

}
