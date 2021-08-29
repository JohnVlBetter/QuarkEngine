#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), mCameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	QK_PROFILE_FUNCTION();

	mCheckerboardTexture = Quark::Texture2D::Create("assets/textures/scene.jpg");
}

void Sandbox2D::OnDetach()
{
	QK_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Quark::Timestep ts)
{
	QK_PROFILE_FUNCTION();

	// Update
	mCameraController.OnUpdate(ts);

	// Render
	{
		QK_PROFILE_SCOPE("Renderer Prep");
		Quark::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Quark::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		QK_PROFILE_SCOPE("Renderer Draw");
		Quark::Renderer2D::BeginScene(mCameraController.GetCamera());
		Quark::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Quark::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Quark::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Quark::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, mCheckerboardTexture, 10.0f);
		Quark::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, mCheckerboardTexture, 20.0f);
		Quark::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	QK_PROFILE_FUNCTION();

	ImGui::Begin("Color");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(mSquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Quark::Event& e)
{
	mCameraController.OnEvent(e);
}