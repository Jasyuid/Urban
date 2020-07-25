#pragma once

#ifdef CB_PLATFORM_WINDOWS
	#ifdef CB_BUILD_DLL
		#define COBALT_API __declspec(dllexport)
	#else
		#define COBALT_API __declspec(dllimport)
	#endif
#else
	#error Not Windows!
#endif

#define BIT(x) (1 << x)