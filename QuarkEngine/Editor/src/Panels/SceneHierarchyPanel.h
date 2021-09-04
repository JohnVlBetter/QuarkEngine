#pragma once

#include "Quark/Core/Core.h"
#include "Quark/Core/Log.h"
#include "Quark/Scene/Scene.h"
#include "Quark/Scene/Entity.h"

namespace Quark {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const SPtr<Scene>& scene);

		void SetContext(const SPtr<Scene>& scene);

		void OnImGuiRender();

		Entity GetSelectedEntity() const { return mSelectionContext; }
		void SetSelectedEntity(Entity entity);
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		SPtr<Scene> mContext;
		Entity mSelectionContext;
	};

}
