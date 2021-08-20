#include <Quark.h>

class ExampleLayer : public Quark::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Quark::Input::IsKeyPressed(QK_KEY_TAB))
			QK_CORE_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Quark::Event& event) override
	{
		if (event.GetEventType() == Quark::EventType::KeyPressed)
		{
			Quark::KeyPressedEvent& e = (Quark::KeyPressedEvent&)event;
			if (e.GetKeyCode() == QK_KEY_Q)
				QK_CORE_TRACE("Tab key is pressed (event)!");
			QK_CORE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Quark::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Quark::ImGuiLayer());
	}
	virtual ~Sandbox() {
	
	}
};

Quark::Application* Quark::CreateApplication() {
	return new Sandbox();
}