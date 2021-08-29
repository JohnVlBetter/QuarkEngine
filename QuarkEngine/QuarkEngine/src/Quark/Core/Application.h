#pragma once

#include "Quark/Core/Core.h"

#include "Quark/Core/Window.h"
#include "Quark/Core/LayerStack.h"
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

		void Close();

		inline static Application& Get() { return *sInstance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		UPtr<Window> mWindow;
		ImGuiLayer* mImGuiLayer;
		bool mRunning = true;
		bool mMinimized = false;
		LayerStack mLayerStack;

		float mLastFrameTime = 0.0f;
	private:
		static Application* sInstance;
	};

	//to be define in client
	Application* CreateApplication();
}