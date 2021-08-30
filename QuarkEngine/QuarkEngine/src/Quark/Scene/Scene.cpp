#include "qkpch.h"
#include "Scene.h"

#include "Components.h"
#include "Quark/Renderer/Renderer2D.h"

#include <glm/glm.hpp>

namespace Quark {

	static void DoMath(const glm::mat4& transform)
	{

	}

	static void OnTransformConstruct(entt::registry& registry, entt::entity entity)
	{

	}

	Scene::Scene()
	{
		
	}

	Scene::~Scene()
	{
	}

	entt::entity Scene::CreateEntity()
	{
		return mRegistry.create();
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = mRegistry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto&[transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}

}