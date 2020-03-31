cmake_minimum_required(VERSION 3.10)

project(Logifypp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(CTest)
include(Colors)
include(Fmt)

# --------------------------------------------------------------------------------
#                         Locate files (change as needed).
# --------------------------------------------------------------------------------

#file(GLOB autopilot_sources ./src/**.cpp ./src/**.c)

file(GLOB autopilot_includes ./include/**.h ./include/**.hpp)
file(GLOB autopilot_interfaces ./include/interface/**.h ./include/interface/**.hpp)
file(GLOB autopilot_sources ./src/**.cpp ./src/**.c)

set(INCLUDES ${autopilot_includes})
set(INTERFACES ${autopilot_interfaces})
set(SOURCES ${autopilot_sources})

set(LIBRARY_NAME LogifyppEngine)

# --------------------------------------------------------------------------------
#                            Build! (Change as needed)
# --------------------------------------------------------------------------------

add_library(${LIBRARY_NAME} OBJECT ${autopilot_includes} ${autopilot_interfaces} ${autopilot_sources})

source_group("Include"            FILES ${autopilot_includes})
source_group("Interface"        FILES ${autopilot_interfaces})
source_group("Source"        FILES ${autopilot_sources})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/interface)

target_link_libraries(${LIBRARY_NAME} PUBLIC fmt)

add_executable(LogifyppBin app/main.cpp)

target_link_libraries(LogifyppBin PRIVATE ${LIBRARY_NAME})

#target_set_warnings(LogifyppBin ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

set_target_properties(
    ${LIBRARY_NAME} LogifyppBin
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_subdirectory(tests)
