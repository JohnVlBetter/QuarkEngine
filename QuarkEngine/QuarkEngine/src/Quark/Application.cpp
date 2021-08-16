#include "qkpch.h"
#include "Application.h"

#include "Log.h"

#include <GLFW/glfw3.h>

namespace Quark {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		mWindow = std::unique_ptr<Window>(Window::Create());
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	
	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		QK_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryApplication))
			while (mRunning)
			{
				QK_CORE_TRACE(e);
				glClearColor(1, 0, 1, 1);
				glClear(GL_COLOR_BUFFER_BIT);
				mWindow->OnUpdate();
			}
		if (e.IsInCategory(EventCategoryInput))
		{
			QK_CORE_TRACE(e);
		}

		while (true);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mRunning = false;
		return true;
	}
}