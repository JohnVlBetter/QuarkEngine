#pragma once

#include "Quark/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Quark {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* mWindowHandle;
	};

}