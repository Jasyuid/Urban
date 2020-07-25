workspace "Urban"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Urban"
	location "Urban"
	kind "SharedLib"
	language "C++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UB_PLATFORM_WINDOWS",
			"UB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/OpenWorld")
		}

	filter "configurations:Debug"
		defines "UB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UB_DIST"
		optimize "On"


project "OpenWorld"
	location "OpenWorld"
	kind "ConsoleApp"
	language "C++"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Urban/vendor/spdlog/include",
		"Urban/src"
	}

	links 
	{
		"Urban"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"UB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "UB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "UB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "UB_DIST"
		optimize "On"