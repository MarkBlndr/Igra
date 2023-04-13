set(HEADER_FILES
	src/BlndrUtil.h
	src/BlndrApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
)

set(SOURCE_FILES
	src/BlndrApp.cpp
	src/GLFWcode/GLFWimplementation.cpp
	src/GameWindow.cpp
)

add_library(Blndr SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(Blndr PRIVATE src/pch.h)
target_link_libraries(Blndr glfw)

add_definitions(-DBLNDR_LIB)
add_definitions(-DBLNDR_GLFW)