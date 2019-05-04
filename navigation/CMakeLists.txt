cmake_minimum_required(VERSION 3.0)
project(sailbot-navigation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Os")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(sailbot-navigation SHARED ${SOURCES})
