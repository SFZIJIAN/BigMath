cmake_minimum_required(VERSION 3.22)
project(BigMath)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/**.c")
add_executable(${PROJECT_NAME} ${SOURCES})