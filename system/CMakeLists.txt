cmake_minimum_required(VERSION 3.10)
project(sailbot-system)

find_package(Protobuf)
find_package(GTest)

include_directories(${Protobuf_INCLUDE_DIRS})

file(GLOB PROTO "${CMAKE_CURRENT_SOURCE_DIR}/proto/*")
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO})

file(GLOB SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/*")
add_executable(sailbot-system ${SOURCE} ${PROTO_SRCS} ${PROTO_HDRS})
target_include_directories(
	sailbot-system 
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(sailbot-system ${Protobuf_LIBRARIES} gps atomic)

file(GLOB CLIENTS "${CMAKE_CURRENT_SOURCE_DIR}/client/*")

foreach(CLIENT ${CLIENTS})
	get_filename_component(EXECUTABLE ${CLIENT} NAME_WE)
	add_executable(${EXECUTABLE} ${CLIENT} ${PROTO_SRCS} ${PROTO_HDRS})
	target_link_libraries(${EXECUTABLE} ${Protobuf_LIBRARIES})
endforeach()
