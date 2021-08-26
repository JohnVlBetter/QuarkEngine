#include "qkpch.h"
#include "Quark/Renderer/GraphicsContext.h"

#include "Quark/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Quark {

	UPtr<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateUPtr<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}