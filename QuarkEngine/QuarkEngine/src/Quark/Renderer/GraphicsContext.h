#pragma once

namespace Quark {

	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

		static UPtr<GraphicsContext> Create(void* window);
	};

}