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
		QK_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Quark::Event& event) override
	{
		QK_CORE_INFO("{0}", event);
	}

};

class Sandbox : public Quark::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	virtual ~Sandbox() {
	
	}
};

Quark::Application* Quark::CreateApplication() {
	return new Sandbox();
}