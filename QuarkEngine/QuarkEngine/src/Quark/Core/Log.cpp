#include "qkpch.h"
#include "Log.h"

namespace Quark {

	SPtr<spdlog::logger> Log::mCoreLogger;
	SPtr<spdlog::logger> Log::mClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%l][%T]%n: %v%$");

		mCoreLogger = spdlog::stdout_color_mt("Quark");
		mCoreLogger->set_level(spdlog::level::trace);
		mClientLogger = spdlog::stdout_color_mt("Client");
		mClientLogger->set_level(spdlog::level::trace);
	}
}