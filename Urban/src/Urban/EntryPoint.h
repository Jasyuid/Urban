#pragma once

#ifdef UB_PLATFORM_WINDOWS

extern Urban::Application* Urban::CreateApplication();

int main(int argc, char** argv)
{
	Urban::Log::Init();
	UB_CORE_WARN("Started Log!");
	int a = 5;
	UB_INFO("Hello! Var={0}", a);

	auto app = Urban::CreateApplication();
	app->Run();
	delete app;
}

#endif
