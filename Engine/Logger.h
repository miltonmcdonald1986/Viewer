#pragma once

#include "ILogger.h"

namespace Viewer
{

	class Logger : public ILogger
	{
	public:
		Logger(const std::string& name, const std::filesystem::path& dir, LogLevel flushLevel, LogLevel activeLevel);
		virtual ~Logger() override = default;

		// Standard log functionality
		virtual void Trace(const std::string& message) const override;
		virtual void Debug(const std::string& message) const override;
		virtual void Info(const std::string& message) const override;
		virtual void Warn(const std::string& message) const override;
		virtual void Error(const std::string& message) const override;
		virtual void Critical(const std::string& message) const override;

		// Specialized logging
		virtual void OpenGLError(GLenum error, const std::string& message = "") const override;

	private:
		std::shared_ptr<spdlog::logger> m_spLogger = nullptr;
	};

}

extern Viewer::Logger gLogger;
