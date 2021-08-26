#include "qkpch.h"
#include "Quark/Renderer/RenderCommand.h"

namespace Quark {

	UPtr<RendererAPI> RenderCommand::sRendererAPI = RendererAPI::Create();

}