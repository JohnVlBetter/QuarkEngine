#pragma once

#include "Quark/Renderer/RendererAPI.h"

namespace Quark {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void SetClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const SPtr<VertexArray>& vertexArray) override;
	};


}