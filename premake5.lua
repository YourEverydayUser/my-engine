workspace "MyEngine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- project definition for MyEngine
project "MyEngine"
    location "MyEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "mepch.h"
    pchsource "MyEngine/src/mepch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    -- when the target platform is windows
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"

        -- custom defines
        defines {
            "ME_PLATFORM_WINDOWS",
            "ME_BUILD_DLL"
        }

        buildoptions {
            "/utf-8" -- Add UTF-8 compilation flag
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    --when the target configuration is debug
    filter "configurations:Debug"
        defines "ME_DEBUG"
        symbols "On"

    --when the target configuration is release
    filter "configurations:Release"
        defines "ME_RELEASE"
        optimize "On"

    --when the target configuration is distribution
    filter "configurations:Dist"
        defines "ME_DEBUG"
        symbols "On"

-- project definition for Sandbox
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "MyEngine/vendor/spdlog/include",
        "MyEngine/src"
    }

    links {
        "MyEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"

        defines {
            "ME_PLATFORM_WINDOWS"
        }

        buildoptions {
            "/utf-8"
        }
    
    filter "configurations:Debug"
        defines "ME_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ME_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "ME_DEBUG"
        symbols "On"
