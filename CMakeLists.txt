cmake_minimum_required(VERSION 3.10)

project(Logifypp VERSION 1.0 LANGUAGES CXX)

# Will be Needed Later
# option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
#                                  Set this to OFF if you want to provide your own warning parameters." ON)
# option(ENABLE_LTO "Enable link time optimization" ON)
option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                         Tests in tests/*.cpp will still be enabled." ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(Colors)
include(CTest)
include(Doctest)

# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------

file(GLOB autopilot_sources ./src/**.cpp ./src/**.c)

set( SOURCES${autopilot_sources}) 

set(TESTFILES        # All .cpp files in tests/
    tests/main.cpp
)
set(LIBRARY_NAME LogifyppEngine)

# --------------------------------------------------------------------------------
#                            Build! (Change as needed)
# --------------------------------------------------------------------------------
# Compile all sources into a library.
add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${LIBRARY_NAME} PUBLIC doctest)

# Set the compile options you want (change as needed). We'll have to enable this to treat all warning as error.
# target_set_warnings(${LIBRARY_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying)
# target_compile_options(${LIBRARY_NAME} ... )  # For setting manually.

# Add an executable for the file app/main.cpp.
# copy these lines if more executable needed.
add_executable(LogifyppBin app/main.cpp)   # Name of exec. and location of file.
target_link_libraries(LogifyppBin PRIVATE ${LIBRARY_NAME})  # Link the executable to library (if it uses it).
#target_set_warnings(LogifyppBin ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

set_target_properties(
    ${LIBRARY_NAME} LogifyppBin
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

# Set up tests (see tests/CMakeLists.txt).
add_subdirectory(tests)
