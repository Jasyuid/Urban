#pragma once

// Defining the entry point for the application on a windows machine
#ifdef CB_PLATFORM_WINDOWS

extern Cobalt::Application* Cobalt::CreateApplication();

int main(int argc, char** argv)
{
	// Initiate the logger
	Cobalt::Log::Init();
	CB_CORE_WARN("Started Log!");

	// TEST LOGS
	int a = 5;
	CB_INFO("Hello {0}!", a);

	// Create application singleton and start main loop
	auto app = Cobalt::CreateApplication();
	app->Run();
	delete app;
}

#endif
