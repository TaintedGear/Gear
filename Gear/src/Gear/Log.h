#pragma once

#include <Memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Gear
{
	class GEAR_API Log
	{
	public:
		Log();
		~Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
		
	};
}

// CORE log macros
#define GR_CORE_INFO(...)   ::Gear::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GR_CORE_TRACE(...)  ::Gear::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GR_CORE_WARN(...)   ::Gear::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GR_CORE_ERROR(...)  ::Gear::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GR_CORE_FATAL(...)  ::Gear::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLIENT log macros
#define GR_INFO(...)   ::Gear::Log::GetClientLogger()->info(__VA_ARGS__)
#define GR_TRACE(...)  ::Gear::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GR_WARN(...)   ::Gear::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GR_ERROR(...)  ::Gear::Log::GetClientLogger()->error(__VA_ARGS__)
#define GR_FATAL(...)  ::Gear::Log::GetClientLogger()->fatal(__VA_ARGS__)
