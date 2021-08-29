#pragma once

#include "qkpch.h"
#include "Quark/Core/Core.h"
#include "Quark/Core/KeyCodes.h"
#include "Quark/Core/MouseCodes.h"

namespace Quark {

	class QUARK_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}