#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gear
{
	std::shared_ptr<spdlog::logger> Log::_coreLogger;
	std::shared_ptr<spdlog::logger> Log::_clientLogger;

	void Log::Init()
	{
		// Set the pattern see:
		// https://github.com/gabime/spdlog/wiki/3.-Custom-formatting
		spdlog::set_pattern("%^[%T] %n: %v%$");

		_coreLogger = spdlog::stdout_color_mt("Gear");
		_coreLogger->set_level(spdlog::level::trace);

		_clientLogger = spdlog::stdout_color_mt("App");
		_clientLogger->set_level(spdlog::level::trace);

		GR_CORE_INFO("Initialized Log!");
	}

	Log::Log()
	{

	}

	Log::~Log()
	{

	}

}