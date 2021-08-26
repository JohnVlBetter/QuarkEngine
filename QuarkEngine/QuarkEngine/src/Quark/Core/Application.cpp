#include "qkpch.h"
#include "Quark/Core/Application.h"

#include "Quark/Core/Log.h"

#include "Quark/Renderer/Renderer.h"

#include "Quark/Core/Input.h"

#include <glfw/glfw3.h>

namespace Quark {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::sInstance = nullptr;

	Application::Application()
	{
		QK_CORE_ASSERT(!sInstance, "Application already exists!");
		sInstance = this;

		mWindow = Window::Create();
		mWindow->SetEventCallback(QK_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		mImGuiLayer = new ImGuiLayer();
		PushOverlay(mImGuiLayer);
	}
	
	Application::~Application()
	{
		Renderer::Shutdown();
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
		dispatcher.Dispatch<WindowCloseEvent>(QK_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(QK_BIND_EVENT_FN(Application::OnWindowResize));

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

				if (!mMinimized)
				{
					for (Layer* layer : mLayerStack)
						layer->OnUpdate(timestep);
				}

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
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		mRunning = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			mMinimized = true;
			return false;
		}

		mMinimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}
}