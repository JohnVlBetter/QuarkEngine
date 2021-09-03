include "./third/premake/premake_customization/solution_items.lua"

workspace "QuarkEngine"
	architecture "x86_64"
	startproject "Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/third/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/third/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/third/imgui"
IncludeDir["glm"] = "%{wks.location}/third/glm"
IncludeDir["stb_image"] = "%{wks.location}/third/stb_image"
IncludeDir["entt"] = "%{wks.location}/third/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/third/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/third/ImGuizmo"

group "Dependencies"
	include "third/premake"
	include "third/GLFW"
	include "third/Glad"
	include "third/imgui"
	include "third/yaml-cpp"
group ""

include "QuarkEngine"
include "Sandbox"
include "Editor"
