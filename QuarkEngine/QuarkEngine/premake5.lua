project "QuarkEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "qkpch.h"
	pchsource "%{wks.location}/QuarkEngine/src/qkpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"%{wks.location}/third/stb_image/**.h",
		"%{wks.location}/third/stb_image/**.cpp",
		"%{wks.location}/third/glm/**.hpp",
		"%{wks.location}/third/glm/**.inl",

		"%{wks.location}/third/ImGuizmo/ImGuizmo.h",
		"%{wks.location}/third/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"%{wks.location}/third/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.assimp}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
		"../third/assimp/lib/assimp-vc141-mtd.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
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
