#pragma once

#include "qkpch.h"
#include "Quark/Core/Core.h"
#include <glm/glm.hpp>
#include "Quark/Core/KeyCodes.h"
#include "Quark/Core/MouseCodes.h"

namespace Quark {

	class QUARK_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}