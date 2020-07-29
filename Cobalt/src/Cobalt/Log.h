#pragma once

#include "Core.h"

// Core log macros
#define CB_CORE_TRACE(s, ...)	::Cobalt::Log::format(Cobalt::Log::SRC_CORE + Cobalt::Log::CAT_TRACE, s, __VA_ARGS__)
#define CB_CORE_INFO(s, ...)	::Cobalt::Log::format(Cobalt::Log::SRC_CORE + Cobalt::Log::CAT_INFO, s, __VA_ARGS__)
#define CB_CORE_WARN(s, ...)	::Cobalt::Log::format(Cobalt::Log::SRC_CORE + Cobalt::Log::CAT_WARN, s, __VA_ARGS__)
#define CB_CORE_ERROR(s, ...)	::Cobalt::Log::format(Cobalt::Log::SRC_CORE + Cobalt::Log::CAT_ERROR, s, __VA_ARGS__)
#define CB_CORE_FATAL(s, ...)	::Cobalt::Log::format(Cobalt::Log::SRC_CORE + Cobalt::Log::CAT_FATAL, s, __VA_ARGS__)

// Client log macros
#define CB_TRACE(s, ...)		::Cobalt::Log::format(Cobalt::Log::SRC_APP + Cobalt::Log::CAT_TRACE, s, __VA_ARGS__)
#define CB_INFO(s, ...)			::Cobalt::Log::format(Cobalt::Log::SRC_APP + Cobalt::Log::CAT_INFO, s, __VA_ARGS__)
#define CB_WARN(s, ...)			::Cobalt::Log::format(Cobalt::Log::SRC_APP + Cobalt::Log::CAT_WARN, s, __VA_ARGS__)
#define CB_ERROR(s, ...)		::Cobalt::Log::format(Cobalt::Log::SRC_APP + Cobalt::Log::CAT_ERROR, s, __VA_ARGS__)
#define CB_FATAL(s, ...)		::Cobalt::Log::format(Cobalt::Log::SRC_APP + Cobalt::Log::CAT_FATAL, s, __VA_ARGS__)

namespace Cobalt {

	class COBALT_API Log
	{
	public:
		// Log categories
		static const unsigned char CAT_TRACE = 0x1;
		static const unsigned char CAT_INFO = 0x2;
		static const unsigned char CAT_WARN = 0x3;
		static const unsigned char CAT_ERROR = 0x4;
		static const unsigned char CAT_FATAL = 0x5;

		// Log sources
		static const unsigned char SRC_CORE = 0x1 << 4;
		static const unsigned char SRC_APP = 0x2 << 4;

		// Window console colors
		enum WIN_FG_COLORS : unsigned char
		{
			FG_BLACK = 0,
			FG_BLUE = 1,
			FG_GREEN = 2,
			FG_CYAN = 3,
			FG_RED = 4,
			FG_MAGENTA = 5,
			FG_BROWN = 6,
			FG_WHITE = 7,
			FG_GRAY = 8,
			FG_LIGHTBLUE = 9,
			FG_LIGHTGREEN = 10,
			FG_LIGHTCYAN = 11,
			FG_LIGHTRED = 12,
			FG_PINK = 13,
			FG_YELLOW = 14,
			FG_LIGHTWHITE = 15
		};

		// Initilize values
		static void Init();

		// Final format loop, move to printing
		static void format(unsigned char type, std::string m);

		// Add variables into string.
		template <typename T, typename... Types>
		static void format(unsigned char type, std::string m, const T& arg1, const Types&... arg2)
		{
			// Go through and find all input spots
			std::stringstream ss;
			ss << "{" << count << "}";
			index = m.find(ss.str());
			// Print error if more argument exist then message slots available
			if (index == std::string::npos)
			{
				int prev_count = count + 1;
				count = 0;
				CB_CORE_ERROR("Logger missing argument {0} in string '{1}'!", prev_count, m);
				return;
			}

			// Insert variable into message
			std::stringstream ss2;
			ss2.str("");
			ss2 << arg1;
			m.replace(index, ss.str().length(), ss2.str());
			count++;

			// Move on to next value
			format(type, m, arg2...);
		}

	private:
		static void print(unsigned char type, std::string m);

	private:
		static int count;
		static size_t index;

		static std::unordered_map<unsigned char, unsigned char> log_colors;

	};

}

//::Cobalt::Log::GetClientLogger()->fatal(__VA_ARGS__)
