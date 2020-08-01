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
	#if defined(CB_PLATFORM_WINDOWS)
		#define CB_DEBUGBREAK() __debugbreak()
	#endif
	#define CB_ENABLE_ASSERTS
#else
	#define CB_DEBUGBREAK()
#endif

// Assert functionality if needed
#ifdef CB_ENABLE_ASSERTS
	#define CB_ASSERT(x, m) { if(!(x)) { CB_ERROR("Assertion Failed: {0} ({1}:{2})", m, __FILE__, __LINE__); CB_DEBUGBREAK(); }}
	#define CB_CORE_ASSERT(x, m) { if(!(x)) { CB_CORE_ERROR("Assertion Failed: {0} ({1}:{2})", m, __FILE__, __LINE__); CB_DEBUGBREAK(); }}
#else
	#define CB_ASSERT(x, m)
	#define CB_CORE_ASSERT(x, m)
#endif

// Macro for changing specific bits
#define BIT(x) (1 << x)

// Bind event to function
#define CB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
