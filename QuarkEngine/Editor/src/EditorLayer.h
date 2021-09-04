#pragma once

#include "Quark.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

#include "Quark/Renderer/EditorCamera.h"

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
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void NewScene();
		void OpenScene();
		void OpenScene(const std::filesystem::path& path);
		void SaveSceneAs();
	private:
		OrthographicCameraController mCameraController;

		// Temp
		SPtr<VertexArray> mSquareVA;
		SPtr<Shader> mFlatColorShader;
		SPtr<Framebuffer> mFramebuffer;

		SPtr<Scene> mActiveScene;
		Entity mSquareEntity;
		Entity mCameraEntity;
		Entity mSecondCamera;

		Entity mHoveredEntity;

		bool mPrimaryCamera = true;

		EditorCamera mEditorCamera;

		SPtr<Texture2D> mCheckerboardTexture;

		bool mViewportFocused = false, mViewportHovered = false;
		glm::vec2 mViewportSize = { 0.0f, 0.0f };
		glm::vec2 mViewportBounds[2];

		glm::vec4 mSquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		int mGizmoType = -1;

		// Panels
		SceneHierarchyPanel mSceneHierarchyPanel;
		ContentBrowserPanel mContentBrowserPanel;
	};
}
