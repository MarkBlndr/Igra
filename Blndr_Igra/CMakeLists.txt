cmake_minimum_required(VERSION 3.24)

project(Blndr_Igra)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DBLNDR_WINDOWS)
elseif(APPLE)
	add_definitions(-DBLNDR_MACOS)
else()
	add_definitions(-DBLNDR_LINUX)
endif()

add_subdirectory(../glfw glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(Blndr)
add_subdirectory(Igra)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Igra)