#include <Quark.h>
#include <Quark/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

class Sandbox : public Quark::Application {
public:
	Sandbox() {
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}
	virtual ~Sandbox() {
	
	}
};

Quark::Application* Quark::CreateApplication() {
	return new Sandbox();
}