#pragma once

#include <glm/glm.hpp>

namespace Quark {

	class Camera
	{
	public:
		Camera(const glm::mat4& projection)
			: mProjection(projection) {}

		const glm::mat4& GetProjection() const { return mProjection; }
	private:
		glm::mat4 mProjection;
	};

}