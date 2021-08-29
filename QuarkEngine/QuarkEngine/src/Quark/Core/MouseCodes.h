#pragma once

namespace Quark
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define QK_MOUSE_BUTTON_0      ::Quark::Mouse::Button0
#define QK_MOUSE_BUTTON_1      ::Quark::Mouse::Button1
#define QK_MOUSE_BUTTON_2      ::Quark::Mouse::Button2
#define QK_MOUSE_BUTTON_3      ::Quark::Mouse::Button3
#define QK_MOUSE_BUTTON_4      ::Quark::Mouse::Button4
#define QK_MOUSE_BUTTON_5      ::Quark::Mouse::Button5
#define QK_MOUSE_BUTTON_6      ::Quark::Mouse::Button6
#define QK_MOUSE_BUTTON_7      ::Quark::Mouse::Button7
#define QK_MOUSE_BUTTON_LAST   ::Quark::Mouse::ButtonLast
#define QK_MOUSE_BUTTON_LEFT   ::Quark::Mouse::ButtonLeft
#define QK_MOUSE_BUTTON_RIGHT  ::Quark::Mouse::ButtonRight
#define QK_MOUSE_BUTTON_MIDDLE ::Quark::Mouse::ButtonMiddle