#pragma once

namespace Quark
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define QK_KEY_SPACE           ::Quark::Key::Space
#define QK_KEY_APOSTROPHE      ::Quark::Key::Apostrophe    /* ' */
#define QK_KEY_COMMA           ::Quark::Key::Comma         /* , */
#define QK_KEY_MINUS           ::Quark::Key::Minus         /* - */
#define QK_KEY_PERIOD          ::Quark::Key::Period        /* . */
#define QK_KEY_SLASH           ::Quark::Key::Slash         /* / */
#define QK_KEY_0               ::Quark::Key::D0
#define QK_KEY_1               ::Quark::Key::D1
#define QK_KEY_2               ::Quark::Key::D2
#define QK_KEY_3               ::Quark::Key::D3
#define QK_KEY_4               ::Quark::Key::D4
#define QK_KEY_5               ::Quark::Key::D5
#define QK_KEY_6               ::Quark::Key::D6
#define QK_KEY_7               ::Quark::Key::D7
#define QK_KEY_8               ::Quark::Key::D8
#define QK_KEY_9               ::Quark::Key::D9
#define QK_KEY_SEMICOLON       ::Quark::Key::Semicolon     /* ; */
#define QK_KEY_EQUAL           ::Quark::Key::Equal         /* = */
#define QK_KEY_A               ::Quark::Key::A
#define QK_KEY_B               ::Quark::Key::B
#define QK_KEY_C               ::Quark::Key::C
#define QK_KEY_D               ::Quark::Key::D
#define QK_KEY_E               ::Quark::Key::E
#define QK_KEY_F               ::Quark::Key::F
#define QK_KEY_G               ::Quark::Key::G
#define QK_KEY_H               ::Quark::Key::H
#define QK_KEY_I               ::Quark::Key::I
#define QK_KEY_J               ::Quark::Key::J
#define QK_KEY_K               ::Quark::Key::K
#define QK_KEY_L               ::Quark::Key::L
#define QK_KEY_M               ::Quark::Key::M
#define QK_KEY_N               ::Quark::Key::N
#define QK_KEY_O               ::Quark::Key::O
#define QK_KEY_P               ::Quark::Key::P
#define QK_KEY_Q               ::Quark::Key::Q
#define QK_KEY_R               ::Quark::Key::R
#define QK_KEY_S               ::Quark::Key::S
#define QK_KEY_T               ::Quark::Key::T
#define QK_KEY_U               ::Quark::Key::U
#define QK_KEY_V               ::Quark::Key::V
#define QK_KEY_W               ::Quark::Key::W
#define QK_KEY_X               ::Quark::Key::X
#define QK_KEY_Y               ::Quark::Key::Y
#define QK_KEY_Z               ::Quark::Key::Z
#define QK_KEY_LEFT_BRACKET    ::Quark::Key::LeftBracket   /* [ */
#define QK_KEY_BACKSLASH       ::Quark::Key::Backslash     /* \ */
#define QK_KEY_RIGHT_BRACKET   ::Quark::Key::RightBracket  /* ] */
#define QK_KEY_GRAVE_ACCENT    ::Quark::Key::GraveAccent   /* ` */
#define QK_KEY_WORLD_1         ::Quark::Key::World1        /* non-US #1 */
#define QK_KEY_WORLD_2         ::Quark::Key::World2        /* non-US #2 */

/* Function keys */
#define QK_KEY_ESCAPE          ::Quark::Key::Escape
#define QK_KEY_ENTER           ::Quark::Key::Enter
#define QK_KEY_TAB             ::Quark::Key::Tab
#define QK_KEY_BACKSPACE       ::Quark::Key::Backspace
#define QK_KEY_INSERT          ::Quark::Key::Insert
#define QK_KEY_DELETE          ::Quark::Key::Delete
#define QK_KEY_RIGHT           ::Quark::Key::Right
#define QK_KEY_LEFT            ::Quark::Key::Left
#define QK_KEY_DOWN            ::Quark::Key::Down
#define QK_KEY_UP              ::Quark::Key::Up
#define QK_KEY_PAGE_UP         ::Quark::Key::PageUp
#define QK_KEY_PAGE_DOWN       ::Quark::Key::PageDown
#define QK_KEY_HOME            ::Quark::Key::Home
#define QK_KEY_END             ::Quark::Key::End
#define QK_KEY_CAPS_LOCK       ::Quark::Key::CapsLock
#define QK_KEY_SCROLL_LOCK     ::Quark::Key::ScrollLock
#define QK_KEY_NUM_LOCK        ::Quark::Key::NumLock
#define QK_KEY_PRINT_SCREEN    ::Quark::Key::PrintScreen
#define QK_KEY_PAUSE           ::Quark::Key::Pause
#define QK_KEY_F1              ::Quark::Key::F1
#define QK_KEY_F2              ::Quark::Key::F2
#define QK_KEY_F3              ::Quark::Key::F3
#define QK_KEY_F4              ::Quark::Key::F4
#define QK_KEY_F5              ::Quark::Key::F5
#define QK_KEY_F6              ::Quark::Key::F6
#define QK_KEY_F7              ::Quark::Key::F7
#define QK_KEY_F8              ::Quark::Key::F8
#define QK_KEY_F9              ::Quark::Key::F9
#define QK_KEY_F10             ::Quark::Key::F10
#define QK_KEY_F11             ::Quark::Key::F11
#define QK_KEY_F12             ::Quark::Key::F12
#define QK_KEY_F13             ::Quark::Key::F13
#define QK_KEY_F14             ::Quark::Key::F14
#define QK_KEY_F15             ::Quark::Key::F15
#define QK_KEY_F16             ::Quark::Key::F16
#define QK_KEY_F17             ::Quark::Key::F17
#define QK_KEY_F18             ::Quark::Key::F18
#define QK_KEY_F19             ::Quark::Key::F19
#define QK_KEY_F20             ::Quark::Key::F20
#define QK_KEY_F21             ::Quark::Key::F21
#define QK_KEY_F22             ::Quark::Key::F22
#define QK_KEY_F23             ::Quark::Key::F23
#define QK_KEY_F24             ::Quark::Key::F24
#define QK_KEY_F25             ::Quark::Key::F25

/* Keypad */
#define QK_KEY_KP_0            ::Quark::Key::KP0
#define QK_KEY_KP_1            ::Quark::Key::KP1
#define QK_KEY_KP_2            ::Quark::Key::KP2
#define QK_KEY_KP_3            ::Quark::Key::KP3
#define QK_KEY_KP_4            ::Quark::Key::KP4
#define QK_KEY_KP_5            ::Quark::Key::KP5
#define QK_KEY_KP_6            ::Quark::Key::KP6
#define QK_KEY_KP_7            ::Quark::Key::KP7
#define QK_KEY_KP_8            ::Quark::Key::KP8
#define QK_KEY_KP_9            ::Quark::Key::KP9
#define QK_KEY_KP_DECIMAL      ::Quark::Key::KPDecimal
#define QK_KEY_KP_DIVIDE       ::Quark::Key::KPDivide
#define QK_KEY_KP_MULTIPLY     ::Quark::Key::KPMultiply
#define QK_KEY_KP_SUBTRACT     ::Quark::Key::KPSubtract
#define QK_KEY_KP_ADD          ::Quark::Key::KPAdd
#define QK_KEY_KP_ENTER        ::Quark::Key::KPEnter
#define QK_KEY_KP_EQUAL        ::Quark::Key::KPEqual

#define QK_KEY_LEFT_SHIFT      ::Quark::Key::LeftShift
#define QK_KEY_LEFT_CONTROL    ::Quark::Key::LeftControl
#define QK_KEY_LEFT_ALT        ::Quark::Key::LeftAlt
#define QK_KEY_LEFT_SUPER      ::Quark::Key::LeftSuper
#define QK_KEY_RIGHT_SHIFT     ::Quark::Key::RightShift
#define QK_KEY_RIGHT_CONTROL   ::Quark::Key::RightControl
#define QK_KEY_RIGHT_ALT       ::Quark::Key::RightAlt
#define QK_KEY_RIGHT_SUPER     ::Quark::Key::RightSuper
#define QK_KEY_MENU            ::Quark::Key::Menu