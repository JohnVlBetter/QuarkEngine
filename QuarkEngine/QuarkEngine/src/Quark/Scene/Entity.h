#pragma once

#include "Scene.h"

#include "entt.hpp"

namespace Quark {

	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			QK_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
			return mScene->mRegistry.emplace<T>(mEntityHandle, std::forward<Args>(args)...);
		}

		template<typename T>
		T& GetComponent()
		{
			QK_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			return mScene->mRegistry.get<T>(mEntityHandle);
		}

		template<typename T>
		bool HasComponent()
		{
			return mScene->mRegistry.has<T>(mEntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			QK_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
			mScene->mRegistry.remove<T>(mEntityHandle);
		}

		operator bool() const { return mEntityHandle != 0; }
	private:
		entt::entity mEntityHandle{ 0 };
		Scene* mScene = nullptr;
	};

}