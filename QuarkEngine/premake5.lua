workspace "QuarkEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "QuarkEngine"
	location "QuarkEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qkpch.h"
	pchsource "QuarkEngine/src/qkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"third/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"QK_PLATFORM_WINDOWS",
			"QUARK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "QK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "QK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "QK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"third/spdlog/include",
		"QuarkEngine/src"
	}

	links
	{
		"QuarkEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"QK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "QK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "QK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "QK_DIST"
		optimize "On"