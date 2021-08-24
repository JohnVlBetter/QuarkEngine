#pragma once

#include "Core.h"

#include "Window.h"
#include "Quark/LayerStack.h"
#include "Quark/Events/Event.h"
#include "Quark/Events/ApplicationEvent.h"

#include "Quark/Core/Timestep.h"
#include "Quark/ImGui/ImGuiLayer.h"

namespace Quark {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *mWindow; }

		inline static Application& Get() { return *sInstance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		UPtr<Window> mWindow;
		ImGuiLayer* mImGuiLayer;
		bool mRunning = true;
		LayerStack mLayerStack;

		float mLastFrameTime = 0.0f;
	private:
		static Application* sInstance;
	};

	//to be define in client
	Application* CreateApplication();
}