#include <Quark.h>
#include <Quark/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Quark {

	class Editor : public Application {
	public:
		Editor() {
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}
		virtual ~Editor() {

		}
	};

	Quark::Application* Quark::CreateApplication() {
		return new Editor();
	}

}