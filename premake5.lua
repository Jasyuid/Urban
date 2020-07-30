workspace "Cobalt"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Cobalt/vendor/GLFW/include"
IncludeDir["Glad"] = "Cobalt/vendor/Glad/include"
IncludeDir["ImGui"] = "Cobalt/vendor/imgui"

group "Dependencies"
	include "Cobalt/vendor/GLFW"
	include "Cobalt/vendor/Glad"
	include "Cobalt/vendor/imgui"
group ""


project "Cobalt"
	location "Cobalt"
	kind "StaticLib"
	language "C++"
	staticruntime "on"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cbpch.h"
	pchsource "Cobalt/src/cbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CB_PLATFORM_WINDOWS",
			"CB_OPENGL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			--("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "CB_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CB_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CB_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "on"

	targetdir  ("bin/" .. outputdir .. "/%{prj.name}")
	objdir  ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Cobalt/src",
		"Cobalt/vendor"
	}

	links 
	{
		"Cobalt"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"CB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CB_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "CB_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "CB_DIST"
		runtime "Release"
		optimize "On"