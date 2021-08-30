workspace "QuarkEngine"
	architecture "x86_64"
	startproject "Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "third/GLFW/include"
IncludeDir["Glad"] = "third/Glad/include"
IncludeDir["ImGui"] = "third/imgui"
IncludeDir["glm"] = "third/glm"
IncludeDir["stb_image"] = "third/stb_image"
IncludeDir["entt"] = "third/entt/include"

group "Dependencies"
	include "third/GLFW"
	include "third/Glad"
	include "third/imgui"
group ""

project "QuarkEngine"
	location "QuarkEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qkpch.h"
	pchsource "QuarkEngine/src/qkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"third/stb_image/**.h",
		"third/stb_image/**.cpp",
		"third/glm/**.hpp",
		"third/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"third/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"QK_PLATFORM_WINDOWS",
			"QUARK_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"NOMINMAX"
		}

	filter "configurations:Debug"
		defines "QK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QK_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"QuarkEngine/src",
		"third",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"QuarkEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"QK_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "QK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QK_DIST"
		runtime "Release"
		optimize "on"

project "Editor"
	location "Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"QuarkEngine/src",
		"third",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"QuarkEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"QK_PLATFORM_WINDOWS",
			"NOMINMAX"
		}

	filter "configurations:Debug"
		defines "QK_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "QK_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "QK_DIST"
		runtime "Release"
		optimize "on"