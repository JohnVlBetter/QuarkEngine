#pragma once

#include "Quark.h"

class Sandbox2D : public Quark::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

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

	Quark::SPtr<Quark::Texture2D> mCheckerboardTexture;

	glm::vec4 mSquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};