#pragma once

#include "Core.h"

#include "Window.h"
#include "Quark/LayerStack.h"
#include "Quark/Events/Event.h"
#include "Quark/Events/ApplicationEvent.h"

#include "Quark/ImGui/ImGuiLayer.h"

#include "Quark/Renderer/Shader.h"
#include "Quark/Renderer/Buffer.h"
#include "Quark/Renderer/VertexArray.h"

#include "Quark/Renderer/OrthographicCamera.h"

namespace Quark {

	class QUARK_API Application
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

		std::unique_ptr<Window> mWindow;
		ImGuiLayer* mImGuiLayer;
		bool mRunning = true;
		LayerStack mLayerStack;

		std::shared_ptr<Shader> mShader;
		std::shared_ptr<VertexArray> mVertexArray;

		std::shared_ptr<Shader> mBlueShader;
		std::shared_ptr<VertexArray> mSquareVA;

		OrthographicCamera mCamera;
	private:
		static Application* sInstance;
	};

	//to be define in client
	Application* CreateApplication();
}