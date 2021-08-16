#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Quark/Events/ApplicationEvent.h"

#include "Window.h"

namespace Quark {

	class QUARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> mWindow;
		bool mRunning = true;
	};

	//to be define in client
	Application* CreateApplication();
}