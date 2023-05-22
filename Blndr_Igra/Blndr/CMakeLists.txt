set(HEADER_FILES
	src/BlndrUtil.h
	src/BlndrApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
	src/Renderer.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
)

set(SOURCE_FILES
	src/BlndrApp.cpp
	src/GLFWcode/GLFWimplementation.cpp
	src/GameWindow.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
)

add_library(Blndr SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../../glfw/include)

target_precompile_headers(Blndr PRIVATE src/pch.h)

target_link_libraries(Blndr glfw glad stbi)

add_definitions(-DBLNDR_LIB)
add_definitions(-DBLNDR_GLFW)
add_definitions(-DBLNDR_OPENGL)
add_definitions(-DBLNDR_WINDOWS)
add_definitions(-DBLNDR_DEBUG=2)