#pragma once

#ifdef CB_PLATFORM_WINDOWS

extern Cobalt::Application* Cobalt::CreateApplication();

int main(int argc, char** argv)
{
	Cobalt::Log::Init();
	CB_CORE_WARN("Started Log!");
	int a = 5;
	CB_INFO("Hello! Var={0}", a);

	auto app = Cobalt::CreateApplication();
	app->Run();
	delete app;
}

#endif
