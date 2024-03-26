workspace "LaBelleRenderer"
architecture "x64"
startproject "LaBelleRenderer"

configurations {
    "Debug",
    "Release",
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDirs = {}
IncludeDirs["GLFW"] = "LaBelleRenderer/vendor/GLFW/include"
IncludeDirs["GLAD"] = "LaBelleRenderer/vendor/GLAD/include"
IncludeDirs["ImGui"] = "LaBelleRenderer/vendor/ImGui"

group "Dependencies"
    include "LaBelleRenderer/vendor/GLFW"
    include "LaBelleRenderer/vendor/GLAD"
    include "LaBelleRenderer/vendor/ImGui"
group ""

project "LaBelleRenderer"
    location "LaBelleRenderer"
    kind "ConsoleApp"
    language "C++"
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

    includedirs {
		"%{prj.name}/src",
        "%{IncludeDirs.GLFW}",
        "%{IncludeDirs.GLAD}",
        "%{IncludeDirs.ImGui}",
	}

    links {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib",
    }

    defines {
        "GLFW_INCLUDE_NONE",
    }

    filter "system:windows"
		cppdialect "C++20"
		systemversion "latest"

        defines {
            "LBR_PLATFORM_WINDOWS",
        }

		filter "configurations:Debug"
            defines "LBR_DEBUG"
            runtime "Debug"
            symbols "On"
        filter "configurations:Release"
            defines "LBR_RELEASE"
            runtime "Release"
            optimize "On"

