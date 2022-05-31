workspace "MasterMind" 
    configurations { "Debug", "Release" } 
    architecture "ARM64"

    filter "system:macosx"
        architecture "ARM64"
        toolset("gcc")


    filter "system:window"
        architecture "x86_64"
        toolset("gcc")

    filter "system:linux"
        architecture "x86_64"
        toolset("gcc")

    flags
	{
		"MultiProcessorCompile",
        "LinkTimeOptimization"
	}

outputbindir = "bin/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}"
outputobjdir = "bin-int/%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}/%{prj.name}"

includedir = "%{wks.location}/src"


project "OpenGL"
    location "src"
    kind "ConsoleApp"  
    language "C"
    buildoptions "-std=c99"
    cdialect "C99"
    staticruntime "on"
    targetdir (outputbindir)
    objdir (outputobjdir)


    files { "main.c", "%{prj.location}/**.h",  
    "%{prj.location}/Players/**.c", "%{prj.location}/Players/**.h",
    "%{prj.location}/Files/**.c", "%{prj.location}/Files/**.h",
    "%{prj.location}/Game/**.c", "%{prj.location}/Game/**.h"
    }
    

    filter "configurations:Debug" 
        defines { "_DEBUG" }  
        symbols "On" 

    filter "configurations:Release" 
        defines { "NDEBUG" }
        optimize "On"
