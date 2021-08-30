#pragma once

#include "entt.hpp"

#include "Quark/Core/Timestep.h"

namespace Quark {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		// TEMP
		entt::registry& Reg() { return mRegistry; }

		void OnUpdate(Timestep ts);
	private:
		entt::registry mRegistry;
	};

}