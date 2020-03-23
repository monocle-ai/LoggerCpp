-- premake5.lua
workspace "SwiFTLog"
   architecture "x86_64"

   configurations 
   {
   "Debug", 
   "Release"
   }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SwiFTLog"
   kind "ConsoleApp"
   language "C++"
   cppdialect "c++17"
   targetdir ("bin/".. outputdir .."-%{prj.name}")
   objdir ("bin/".. outputdir .."-%{prj.name}")

   files 
   {
    "include/**.h",    
    "src/**.cpp",
    "app/**.cpp"
   }
   
   defines
   {
		"_CRT_SECURE_NO_WARNINGS"
   }

   includedirs {
   "include", 
   }

   filter "system.windows"
     
      staticruntime "On"
      systemversion "latest"
  
   filter "configurations:Debug"
      
      defines { "DEBUG" }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      
      defines { "NDEBUG" }
      runtime "Release"
      optimize "On"