#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Quark {

	class QUARK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return mCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return mClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> mCoreLogger;
		static std::shared_ptr<spdlog::logger> mClientLogger;
	};
}

//Core log
#define QK_CORE_TRACE(...)		::Quark::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QK_CORE_INFO(...)		::Quark::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QK_CORE_WARNING(...)	::Quark::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QK_CORE_ERROR(...)		::Quark::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QK_CORE_CRITICAL(...)	::Quark::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log
#define QK_CLIENT_TRACE(...)	::Quark::Log::GetClientLogger()->trace(__VA_ARGS__)
#define QK_CLIENT_INFO(...)		::Quark::Log::GetClientLogger()->info(__VA_ARGS__)
#define QK_CLIENT_WARNING(...)	::Quark::Log::GetClientLogger()->warn(__VA_ARGS__)
#define QK_CLIENT_ERROR(...)	::Quark::Log::GetClientLogger()->error(__VA_ARGS__)
#define QK_CLIENT_CRITICAL(...)	::Quark::Log::GetClientLogger()->critical(__VA_ARGS__)