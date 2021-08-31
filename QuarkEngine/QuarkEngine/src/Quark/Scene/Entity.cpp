#include "qkpch.h"
#include "Entity.h"

namespace Quark {

	Entity::Entity(entt::entity handle, Scene* scene)
		: mEntityHandle(handle), mScene(scene)
	{
	}

}