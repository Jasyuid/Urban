#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Urban {

	class URBAN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define UB_CORE_TRACE(...)	::Urban::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UB_CORE_INFO(...)	::Urban::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UB_CORE_WARN(...)	::Urban::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UB_CORE_ERROR(...)	::Urban::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UB_CORE_FATAL(...)	::Urban::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macors
#define UB_TRACE(...)		::Urban::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UB_INFO(...)		::Urban::Log::GetClientLogger()->info(__VA_ARGS__)
#define UB_WARN(...)		::Urban::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UB_ERROR(...)		::Urban::Log::GetClientLogger()->error(__VA_ARGS__)
#define UB_FATAL(...)		::Urban::Log::GetClientLogger()->fatal(__VA_ARGS__)
