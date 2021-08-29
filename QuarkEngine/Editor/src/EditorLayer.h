#pragma once

#include "Quark.h"

namespace Quark {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		OrthographicCameraController mCameraController;

		// Temp
		SPtr<VertexArray> mSquareVA;
		SPtr<Shader> mFlatColorShader;
		SPtr<Framebuffer> mFramebuffer;

		SPtr<Texture2D> mCheckerboardTexture;

		glm::vec2 mViewportSize = { 0.0f, 0.0f };

		glm::vec4 mSquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	};
}