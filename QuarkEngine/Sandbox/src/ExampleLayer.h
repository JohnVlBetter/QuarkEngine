#pragma once

#include "Quark.h"

class ExampleLayer : public Quark::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Quark::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Quark::Event& e) override;
private:
	Quark::ShaderLibrary mShaderLibrary;
	Quark::SPtr<Quark::Shader> mShader;
	Quark::SPtr<Quark::VertexArray> mVertexArray;

	Quark::SPtr<Quark::Shader> mFlatColorShader;
	Quark::SPtr<Quark::VertexArray> mSquareVA;

	Quark::SPtr<Quark::Texture2D> mTexture, mChernoLogoTexture;

	Quark::OrthographicCameraController mCameraController;
	glm::vec3 mSquareColor = { 0.2f, 0.3f, 0.8f };
};
