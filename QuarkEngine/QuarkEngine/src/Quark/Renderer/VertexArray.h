#pragma once

#include <memory>
#include "Quark/Renderer/Buffer.h"

namespace Quark {

	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const SPtr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const SPtr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<SPtr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const SPtr<IndexBuffer>& GetIndexBuffer() const = 0;

		static SPtr<VertexArray> Create();
	};

}