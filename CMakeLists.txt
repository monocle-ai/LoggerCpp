cmake_minimum_required(VERSION 3.10)

project(SwiFTLog VERSION 1.0 LANGUAGES CXX)

# Will be Needed Later
# option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
#                                  Set this to OFF if you want to provide your own warning parameters." ON)
# option(ENABLE_LTO "Enable link time optimization" ON)
# option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
#                         Tests in tests/*.cpp will still be enabled." ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(Colors)

# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
    src/clock.cpp
    src/levelUtils.cpp
)
set(LIBRARY_NAME swiftlogEngine)

# --------------------------------------------------------------------------------
#                            Build! (Change as needed)
# --------------------------------------------------------------------------------
# Compile all sources into a library.
add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Set the compile options you want (change as needed). We'll have to enable this to treat all warning as error.
# target_set_warnings(${LIBRARY_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying) 
# target_compile_options(${LIBRARY_NAME} ... )  # For setting manually.

# Add an executable for the file SwiFTLog/main.cpp.
# copy these lines if more executable needed.
add_executable(SwiFTLogExe SwiFTLog/main.cpp)   # Name of exec. and location of file.
target_link_libraries(SwiFTLogExe PRIVATE ${LIBRARY_NAME})  # Link the executable to library (if it uses it).
#target_set_warnings(SwiFTLogExe ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

set_target_properties(
    ${LIBRARY_NAME} SwiFTLog 
      PROPERTIES 
        CXX_STANDARD 17 
        CXX_STANDARD_REQUIRED YES 
        CXX_EXTENSIONS NO
)
