include_directories(${SwiFTLog_SOURCE_DIR}/SwiFTLog/include)

add_library(CLoggerClock clock.cpp)

add_library(CLoggerUtils levelUtils.cpp)

link_directories(${SwiFTLog_SOURCE_DIR}/SwiFTLog/src)

add_executable(SwiFTLog main.cpp)

target_link_libraries(SwiFTLog CLoggerClock CLoggerUtils)