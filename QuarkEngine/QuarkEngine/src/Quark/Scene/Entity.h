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
			T& component = mScene->mRegistry.emplace<T>(mEntityHandle, std::forward<Args>(args)...);
			mScene->OnComponentAdded<T>(*this, component);
			return component;
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
		operator entt::entity() const { return mEntityHandle; }
		operator uint32_t() const { return (uint32_t)mEntityHandle; }

		bool operator==(const Entity& other) const
		{
			return mEntityHandle == other.mEntityHandle && mScene == other.mScene;
		}

		bool operator!=(const Entity& other) const
		{
			return !(*this == other);
		}

		bool isNull() { return mEntityHandle == entt::null; }
	private:
		entt::entity mEntityHandle{ entt::null };
		Scene* mScene = nullptr;
	};

}
