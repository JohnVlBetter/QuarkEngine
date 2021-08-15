#pragma once

#ifdef QK_PLATFORM_WINDOWS

extern Quark::Application* Quark::CreateApplication();

int main(int argc,char** argv) {
	Quark::Log::Init();
	QK_CORE_WARNING("Initialized Log!");
	QK_CLIENT_INFO("Hello!{0}",6);

	auto app = Quark::CreateApplication();
	app->Run();
	delete app;
	while (true);
}

#endif