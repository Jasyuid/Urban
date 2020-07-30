#pragma once

// DLL loading macros for Windows (Not needed anymore since Cobalt is now a static library)
#ifdef CB_PLATFORM_WINDOWS
	#ifdef CB_BUILD_DLL
		#define COBALT_API __declspec(dllexport)
	#else
		#define COBALT_API 
	#endif
#else
	#error Not Windows!
#endif

// Enable asserts if in debug mode
#ifdef CB_DEBUG
	#define CB_ENABLE_ASSERTS
#endif

// Assert functionality if needed
#ifdef CB_ENABLE_ASSERTS
	#define CB_ASSERT(x, ...) { if(!(x)) { CB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define CB_CORE_ASSERT(x, ...) { if(!(x)) { CB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define CB_ASSERT(x, ...)
	#define CB_CORE_ASSERT(x, ...)
#endif

// Macro for changing specific bits
#define BIT(x) (1 << x)

// Bind event to function
#define CB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
