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

		QK_CORE_INFO("---------------------------------------");
		QK_CORE_INFO("OpenGL Info:");
		QK_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		QK_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		QK_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
		QK_CORE_INFO("---------------------------------------");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(mWindowHandle);
	}

}