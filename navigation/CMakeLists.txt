cmake_minimum_required(VERSION 3.0)
project(sailbot-navigation)

include(ExternalData)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(sailbot-navigation SHARED ${SOURCES})
