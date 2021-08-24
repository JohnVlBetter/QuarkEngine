#include "qkpch.h"
#include "Application.h"

#include "Log.h"

#include "Quark/Renderer/Renderer.h"

#include "Input.h"

#include <glfw/glfw3.h>

namespace Quark {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::sInstance = nullptr;

	Application::Application()
	{
		QK_CORE_ASSERT(!sInstance, "Application already exists!");
		sInstance = this;

		mWindow = UPtr<Window>(Window::Create());
		mWindow->SetEventCallback(BIND_EVENT_FN(OnEvent));

		Renderer::Init();

		mImGuiLayer = new ImGuiLayer();
		PushOverlay(mImGuiLayer);
	}
	
	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		mLayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		mLayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));

		for (auto it = mLayerStack.end(); it != mLayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryApplication))
			while (mRunning)
			{
				float time = (float)glfwGetTime();
				Timestep timestep = time - mLastFrameTime;
				mLastFrameTime = time;

				for (Layer* layer : mLayerStack)
					layer->OnUpdate(timestep);

				mImGuiLayer->Begin();
				for (Layer* layer : mLayerStack)
					layer->OnImGuiRender();
				mImGuiLayer->End();

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