#include "qkpch.h"
#include "Framebuffer.h"

#include "Quark/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Quark {

	SPtr<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateSPtr<OpenGLFramebuffer>(spec);
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}