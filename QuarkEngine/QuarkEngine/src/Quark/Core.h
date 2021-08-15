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