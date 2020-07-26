#include "cbpch.h"
#include "Log.h"

#ifdef CB_PLATFORM_WINDOWS
	#define SET_CONSOLE_COLOR(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
#else
	#define SET_CONSOLE_COLOR(x)
#endif

namespace Cobalt {

	int Log::count;
	size_t Log::index;
	std::unordered_map<unsigned char, unsigned char> Log::log_colors;

	void Log::Init()
	{
		count = 0;

		// Setting colors for all log types
		log_colors[SRC_CORE + CAT_TRACE] = FG_GREEN;
		log_colors[SRC_CORE + CAT_INFO] = FG_WHITE;
		log_colors[SRC_CORE + CAT_WARN] = FG_YELLOW;
		log_colors[SRC_CORE + CAT_ERROR] = FG_LIGHTRED;
		log_colors[SRC_CORE + CAT_FATAL] = FG_RED;
		log_colors[SRC_APP + CAT_TRACE] = FG_GREEN;
		log_colors[SRC_APP + CAT_INFO] = FG_WHITE;
		log_colors[SRC_APP + CAT_WARN] = FG_YELLOW;
		log_colors[SRC_APP + CAT_ERROR] = FG_LIGHTRED;
		log_colors[SRC_APP + CAT_FATAL] = FG_RED;
	}

	void Log::print(unsigned char type, std::string m)
	{
		// Set the text color
		SET_CONSOLE_COLOR(log_colors[type]);

		// Get the current time
		time_t now = time(0);
		struct tm time_info;
		localtime_s(&time_info, &now);
		// Print the time
		if (time_info.tm_hour < 10)
			std::cout << "[0" << time_info.tm_hour << ":";
		else
			std::cout << "[" << time_info.tm_hour << ":";
		if (time_info.tm_min < 10)
			std::cout << "0" << time_info.tm_min << ":";
		else
			std::cout << time_info.tm_min << ":";
		if (time_info.tm_sec < 10)
			std::cout << "0" << time_info.tm_sec << "] ";
		else
			std::cout << time_info.tm_sec << "] ";

		// Print the source
		if ((type & 0xf0) == SRC_CORE)
			std::cout << "Core: ";
		else if((type & 0xf0) == SRC_APP)
			std::cout << "App: ";

		// Print the message
		std::cout << m << std::endl;

		// Reset the text color
		SET_CONSOLE_COLOR(FG_WHITE);
	}

}