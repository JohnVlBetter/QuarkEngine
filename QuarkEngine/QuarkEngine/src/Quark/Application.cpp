#include "Application.h"

#include "Events/MouseEvent.h"
#include "Log.h"

namespace Quark {

	Application::Application()
	{
	}
	
	Application::~Application()
	{
	}

	void Application::Run() {
		MouseButtonPressedEvent e(0);
		if (e.IsInCategory(EventCategoryApplication))
		{
			QK_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			QK_CORE_ERROR(e);
		}

		while (true);
	}
}