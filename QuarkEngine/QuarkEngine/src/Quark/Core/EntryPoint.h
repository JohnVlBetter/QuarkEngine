#pragma once
#include "Quark/Core/Core.h"

#ifdef QK_PLATFORM_WINDOWS

extern Quark::Application* Quark::CreateApplication();

int main(int argc,char** argv) {
	Quark::Log::Init();

	QK_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = Quark::CreateApplication();
	QK_PROFILE_END_SESSION();

	QK_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	QK_PROFILE_END_SESSION();

	QK_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Shutdown.json");
	delete app;
	QK_PROFILE_END_SESSION();
}

#endif