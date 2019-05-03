cmake_minimum_required(VERSION 3.10)
project(bcit-sailbot)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/system")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/navigation")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/simulation")
