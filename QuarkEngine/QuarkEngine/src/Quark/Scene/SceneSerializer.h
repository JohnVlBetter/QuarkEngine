#pragma once
#include "Quark/Core/Core.h"
#include "Scene.h"

namespace Quark {

	class SceneSerializer
	{
	public:
		SceneSerializer(const SPtr<Scene>& scene);

		void Serialize(const std::string& filepath);
		void SerializeRuntime(const std::string& filepath);

		bool Deserialize(const std::string& filepath);
		bool DeserializeRuntime(const std::string& filepath);
	private:
		SPtr<Scene> mScene;
	};

}
