#pragma once

#include "Quark/Core/PlatformDetection.h"

#ifdef QK_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#ifdef QK_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Quark/Core/Core.h"
#include "Quark/Core/Log.h"

#include "Quark/Debug/Instrumentor.h"
