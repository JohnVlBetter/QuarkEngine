#pragma once

#include "Quark/Renderer/VertexArray.h"

namespace Quark {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const SPtr<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const SPtr<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<SPtr<VertexBuffer>>& GetVertexBuffers() const { return mVertexBuffers; }
		virtual const SPtr<IndexBuffer>& GetIndexBuffer() const { return mIndexBuffer; }
	private:
		uint32_t mRendererID;
		uint32_t mVertexBufferIndex = 0;
		std::vector<SPtr<VertexBuffer>> mVertexBuffers;
		SPtr<IndexBuffer> mIndexBuffer;
	};

}