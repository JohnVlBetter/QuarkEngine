#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

template<typename Fn>
class Timer
{
public:
	Timer(const char* name, Fn&& func)
		: mName(name), mFunc(func), mStopped(false)
	{
		mStartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!mStopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(mStartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		mStopped = true;

		float duration = (end - start) * 0.001f;
		mFunc({ mName, duration });
	}
private:
	const char* mName;
	Fn mFunc;
	std::chrono::time_point<std::chrono::steady_clock> mStartTimepoint;
	bool mStopped;
};

#define PROFILE_SCOPE(name) Timer timer(name, [&](ProfileResult profileResult) { mProfileResults.push_back(profileResult); })


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), mCameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	mCheckerboardTexture = Quark::Texture2D::Create("assets/textures/scene.jpg");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Quark::Timestep ts)
{
	PROFILE_SCOPE("Sandbox2D::OnUpdate");

	// Update
	{
		PROFILE_SCOPE("CameraController::OnUpdate");
		mCameraController.OnUpdate(ts);
	}

	// Render
	{
		PROFILE_SCOPE("Renderer Prep");
		Quark::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Quark::RenderCommand::Clear();
	}

	{
		PROFILE_SCOPE("Renderer Draw");
		Quark::Renderer2D::BeginScene(mCameraController.GetCamera());
		Quark::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Quark::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Quark::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, mCheckerboardTexture);
		Quark::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Color");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(mSquareColor));

	for (auto& result : mProfileResults)
	{
		char label[50];
		strcpy(label, "%.3fms ");
		strcat(label, result.Name);
		ImGui::Text(label, result.Time);
	}
	mProfileResults.clear();

	ImGui::End();
}

void Sandbox2D::OnEvent(Quark::Event& e)
{
	mCameraController.OnEvent(e);
}