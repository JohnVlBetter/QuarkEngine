#pragma once

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Quark {

	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};
	public:
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const SPtr<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return sAPI; }
	private:
		static API sAPI;
	};

}