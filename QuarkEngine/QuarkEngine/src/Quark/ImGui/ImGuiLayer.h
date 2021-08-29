#pragma once

#include "Quark/Core/Layer.h"

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
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { mBlockEvents = block; }
	private:
		bool mBlockEvents = true;
		float mTime = 0.0f;
	};

}