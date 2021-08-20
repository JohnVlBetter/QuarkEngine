#pragma once

#ifdef QK_PLATFORM_WINDOWS
	#ifdef QUARK_BUILD_DLL
		#define QUARK_API __declspec(dllexport)
	#else
		#define QUARK_API __declspec(dllimport)
	#endif
#else
	#error Quark only supports Windows!
#endif

#ifdef QK_DEBUG
	#define QK_ENABLE_ASSERTS
#endif

#ifdef QK_ENABLE_ASSERTS
	#define QK_CORE_ASSERT(x, ...) { if(!(x)) { QK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define QK_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x) 

#define QK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1) 