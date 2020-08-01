#pragma once

// Defining the entry point for the application on a windows machine
// Don't think the windows part matters for this file
#ifdef CB_PLATFORM_WINDOWS

#include <iostream>
#include <Windows.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

extern Cobalt::Application* Cobalt::CreateApplication();

int main(int argc, char** argv)
{
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld);

	// TEST LOGS
	CB_CORE_WARN("Started Log!");
	CB_INFO("Hello {0}!", "world");

	// Create application singleton and start main loop
	auto app = Cobalt::CreateApplication();
	app->Run();
	delete app;

	_CrtMemCheckpoint(&sNew);
	if (_CrtMemDifference(&sDiff, &sOld, &sNew))
	{
		CB_CORE_ERROR("Memory leak detected!");
		OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
		_CrtMemDumpStatistics(&sDiff);
		OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
		_CrtMemDumpAllObjectsSince(&sOld);
		OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
		_CrtDumpMemoryLeaks();
	}

	return 0;
}

#endif
