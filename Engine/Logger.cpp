#include "pch.h"
#include "Logger.h"
#include "Utilities.h"

Viewer::Logger gLogger("Engine", LOGS_DIR, Viewer::LogLevel::Warn, Viewer::LogLevel::Info);

namespace
{

	std::optional<spdlog::level::level_enum> ConvertLogLevel(Viewer::LogLevel level)
	{
		switch (level)
		{
		case Viewer::Trace:
			return spdlog::level::trace;
		case Viewer::Debug:
			return spdlog::level::debug;
		case Viewer::Info:
			return spdlog::level::info;
		case Viewer::Warn:
			return spdlog::level::warn;
		case Viewer::Error:
			return spdlog::level::err;
		case Viewer::Critical:
			return spdlog::level::critical;
		}

		return std::nullopt;
	}

}

namespace Viewer
{
	Logger::Logger(const std::string& name, const std::filesystem::path& dir, LogLevel flushLevel, LogLevel activeLevel)
	{
		std::filesystem::path pathToLog = dir / (name + ".log");
		m_spLogger = spdlog::basic_logger_mt(name, pathToLog.string(), true);
		if (m_spLogger)
		{
			m_spLogger->flush_on(ConvertLogLevel(flushLevel).value_or(spdlog::level::warn));

#ifdef _DEBUG
			m_spLogger->set_level(spdlog::level::debug);
#else
			m_spLogger->set_level(ConvertLogLevel(activeLevel).value_or(spdlog::level::info));
#endif
		}
	}

	void Logger::Trace(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->trace(message);
	}

	void Logger::Debug(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->debug(message);
	}

	void Logger::Info(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->info(message);
	}

	void Logger::Warn(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->warn(message);
	}

	void Logger::Error(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->error(message);
	}

	void Logger::Critical(const std::string& message) const
	{
		if (m_spLogger)
			m_spLogger->critical(message);
	}

	void Logger::OpenGLError(GLenum error, const std::string& message) const
	{
		if (m_spLogger)
		{
			m_spLogger->error(std::format("OpenGL Error: {}", Utilities::GLEnumToString(error)));
			if (!message.empty())
				m_spLogger->info(message);
		}
	}

}
