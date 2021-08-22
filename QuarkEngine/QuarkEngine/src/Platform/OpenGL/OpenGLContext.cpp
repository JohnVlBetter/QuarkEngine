#include "qkpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Quark {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: mWindowHandle(windowHandle)
	{
		QK_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(mWindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		QK_CORE_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindowHandle);
	}

}