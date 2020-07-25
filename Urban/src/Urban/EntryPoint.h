#pragma once

#ifdef UB_PLATFORM_WINDOWS

extern Urban::Application* Urban::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Urban::CreateApplication();
	app->Run();
	delete app;
}

#endif
