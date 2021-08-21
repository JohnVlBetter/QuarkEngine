#pragma once

#include "Quark/Layer.h"

#include "Quark/Events/ApplicationEvent.h"
#include "Quark/Events/KeyEvent.h"
#include "Quark/Events/MouseEvent.h"

namespace Quark {

	class QUARK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float mTime = 0.0f;
	};

}