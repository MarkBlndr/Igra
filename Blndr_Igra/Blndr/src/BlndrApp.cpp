#include "pch.h"
#include "BlndrApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Shader.h"
#include "Image.h"
#include "Renderer.h"

namespace Blndr
{
	void BlndrApp::Run()
	{
		Renderer renderer;

		Image image{ "../Assets/Images/test.png" };
		image.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		while (true)
		{
			glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			renderer.Draw(image, { 200, 100 });

			OnUpdate();
		}
	}
}