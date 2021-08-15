#pragma once

#include "Core.h"

namespace Quark {

	class QUARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be define in client
	Application* CreateApplication();
}