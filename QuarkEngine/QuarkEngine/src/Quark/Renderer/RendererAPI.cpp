#include "qkpch.h"
#include "Quark/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Quark {

	RendererAPI::API RendererAPI::sAPI = RendererAPI::API::OpenGL;

	UPtr<RendererAPI> RendererAPI::Create()
	{
		switch (sAPI)
		{
		case RendererAPI::API::None:    QK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateUPtr<OpenGLRendererAPI>();
		}

		QK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}