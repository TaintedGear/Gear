-- Gear SLN
workspace "Gear"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Gear
project "Gear"
	location "Gear"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GR_PLATFORM_WINDOWS",
			"GR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GR_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "GR_DIST"
		symbols "On"

-- Sandbox
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
		"Gear/vendor/spdlog/include",
		"Gear/src"
	}

	links
	{
		"Gear"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GR_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "GR_DIST"
		symbols "On"