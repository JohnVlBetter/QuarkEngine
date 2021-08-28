#include "qkpch.h"
#include "Quark/Renderer/Buffer.h"

#include "Quark/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Quark {

	SPtr<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLVertexBuffer>(size);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	SPtr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLVertexBuffer>(vertices, size);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	SPtr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLIndexBuffer>(indices, size);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}