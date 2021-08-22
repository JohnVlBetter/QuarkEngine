#include "qkpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Quark {

	RendererAPI* RenderCommand::sRendererAPI = new OpenGLRendererAPI;

}