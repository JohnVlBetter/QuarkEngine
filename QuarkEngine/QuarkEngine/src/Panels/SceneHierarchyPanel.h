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
	private:
		void DrawEntityNode(Entity entity);
	private:
		SPtr<Scene> mContext;
		Entity mSelectionContext;
	};

}
