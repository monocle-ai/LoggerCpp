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

set(SOURCES
    src/chrono_lgf.cpp
    src/formatter_lgf.cpp
    src/levelUtils_lgf.cpp
    src/lockable_lgf.cpp
    src/sourceInfo_lgf.cpp
)

set(LIBRARY_NAME LogifyppEngine)

# --------------------------------------------------------------------------------
#                            Build! (Change as needed)
# --------------------------------------------------------------------------------

add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

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
