#pragma once

#include "Quark.h"

class EditorLayer : public Quark::Layer
{
public:
	EditorLayer();
	virtual ~EditorLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Quark::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Quark::Event& e) override;
private:
	Quark::OrthographicCameraController mCameraController;

	// Temp
	Quark::SPtr<Quark::VertexArray> mSquareVA;
	Quark::SPtr<Quark::Shader> mFlatColorShader;
	Quark::SPtr<Quark::Framebuffer> mFramebuffer;

	Quark::SPtr<Quark::Texture2D> mCheckerboardTexture;

	glm::vec4 mSquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};