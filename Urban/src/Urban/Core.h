#pragma once

#ifdef UB_PLATFORM_WINDOWS
	#ifdef UB_BUILD_DLL
		#define URBAN_API __declspec(dllexport)
	#else
		#define URBAN_API __declspec(dllimport)
	#endif
#else
	#error Not Windows!
#endif