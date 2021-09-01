project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/third/spdlog/include",
		"%{wks.location}/QuarkEngine/src",
		"%{wks.location}/third",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"QuarkEngine"
	}

	filter "system:windows"
		systemversion "latest"

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