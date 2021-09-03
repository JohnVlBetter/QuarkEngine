#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Quark/Scene/SceneSerializer.h"

#include "Quark/Utils/PlatformUtils.h"

#include "EditorLayer.h"

namespace Quark {

	EditorLayer::EditorLayer()
		: Layer("EditorLayer"), mCameraController(1280.0f / 720.0f), mSquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
	{
	}

	void EditorLayer::OnAttach()
	{
		QK_PROFILE_FUNCTION();

		mCheckerboardTexture = Quark::Texture2D::Create("assets/textures/scene.jpg");

		Quark::FramebufferSpecification fbSpec;
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		mFramebuffer = Framebuffer::Create(fbSpec);

		mActiveScene = CreateSPtr<Scene>();
		mSceneHierarchyPanel.SetContext(mActiveScene);
	}

	void EditorLayer::OnDetach()
	{
		QK_PROFILE_FUNCTION();
	}

	void EditorLayer::OnUpdate(Quark::Timestep ts)
	{
		QK_PROFILE_FUNCTION();

		// Resize
		if (Quark::FramebufferSpecification spec = mFramebuffer->GetSpecification();
			mViewportSize.x > 0.0f && mViewportSize.y > 0.0f && // zero sized framebuffer is invalid
			(spec.Width != mViewportSize.x || spec.Height != mViewportSize.y))
		{
			mFramebuffer->Resize((uint32_t)mViewportSize.x, (uint32_t)mViewportSize.y);
			mCameraController.OnResize(mViewportSize.x, mViewportSize.y);

			mActiveScene->OnViewportResize((uint32_t)mViewportSize.x, (uint32_t)mViewportSize.y);
		}

		// Update
		if (mViewportFocused)
			mCameraController.OnUpdate(ts);

		// Render
		Renderer2D::ResetStats();
		mFramebuffer->Bind();
		RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		RenderCommand::Clear();

		// Update scene
		mActiveScene->OnUpdate(ts);

		mFramebuffer->Unbind();
	}

	void EditorLayer::OnImGuiRender()
	{
		QK_PROFILE_FUNCTION();

		// Note: Switch this to true to enable dockspace
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		ImGuiStyle& style = ImGui::GetStyle();
		float minWinSizeX = style.WindowMinSize.x;
		style.WindowMinSize.x = 370.0f;
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}
		style.WindowMinSize.x = minWinSizeX;

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				// Disabling fullscreen would allow the window to be moved to the front of other windows, 
				// which we can't undo at the moment without finer window depth/z control.
				//ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);
				if (ImGui::MenuItem("New", "Ctrl+N"))
					NewScene();

				if (ImGui::MenuItem("Open...", "Ctrl+O"))
					OpenScene();

				if (ImGui::MenuItem("Save As...", "Ctrl+Shift+S"))
					SaveSceneAs();

				if (ImGui::MenuItem("Exit")) Quark::Application::Get().Close();
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
		mSceneHierarchyPanel.OnImGuiRender();

		ImGui::Begin("Stats");

		auto stats = Quark::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", stats.DrawCalls);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");

		mViewportFocused = ImGui::IsWindowFocused();
		mViewportHovered = ImGui::IsWindowHovered();
		Application::Get().GetImGuiLayer()->BlockEvents(!mViewportFocused || !mViewportHovered);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		mViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

		uint64_t textureID = mFramebuffer->GetColorAttachmentRendererID();
		ImGui::Image(reinterpret_cast<void*>(textureID), ImVec2{ mViewportSize.x, mViewportSize.y }, ImVec2{ 1, 0 }, ImVec2{ 0, 1 });
		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::End();
	}

	void EditorLayer::OnEvent(Quark::Event& e)
	{
		mCameraController.OnEvent(e);

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(QK_BIND_EVENT_FN(EditorLayer::OnKeyPressed));
	}

	bool EditorLayer::OnKeyPressed(KeyPressedEvent& e)
	{
		// Shortcuts
		if (e.GetRepeatCount() > 0)
			return false;

		bool control = Input::IsKeyPressed(Key::LeftControl) || Input::IsKeyPressed(Key::RightControl);
		bool shift = Input::IsKeyPressed(Key::LeftShift) || Input::IsKeyPressed(Key::RightShift);
		switch (e.GetKeyCode())
		{
		case Key::N:
		{
			if (control)
				NewScene();

			break;
		}
		case Key::O:
		{
			if (control)
				OpenScene();

			break;
		}
		case Key::S:
		{
			if (control && shift)
				SaveSceneAs();

			break;
		}
		}
	}

	void EditorLayer::NewScene()
	{
		mActiveScene = CreateSPtr<Scene>();
		mActiveScene->OnViewportResize((uint32_t)mViewportSize.x, (uint32_t)mViewportSize.y);
		mSceneHierarchyPanel.SetContext(mActiveScene);
	}

	void EditorLayer::OpenScene()
	{
		std::string filepath = FileDialogs::OpenFile("Quark Scene (*.quark)\0*.quark\0");
		if (!filepath.empty())
		{
			mActiveScene = CreateSPtr<Scene>();
			mActiveScene->OnViewportResize((uint32_t)mViewportSize.x, (uint32_t)mViewportSize.y);
			mSceneHierarchyPanel.SetContext(mActiveScene);

			SceneSerializer serializer(mActiveScene);
			serializer.Deserialize(filepath);
		}
	}

	void EditorLayer::SaveSceneAs()
	{
		std::string filepath = FileDialogs::SaveFile("Quark Scene (*.quark)\0*.quark\0");
		if (!filepath.empty())
		{
			SceneSerializer serializer(mActiveScene);
			serializer.Serialize(filepath);
		}
	}

}
