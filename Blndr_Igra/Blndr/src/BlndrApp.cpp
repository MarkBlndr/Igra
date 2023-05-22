#include "pch.h"
#include "BlndrApp.h"

#include "Shader.h"
#include "Image.h"
#include "Renderer.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

namespace Blndr
{
	void BlndrApp::Run()
	{
		Renderer renderer;

		Image image{ "../Assets/Images/test2.png" };
		image.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		mNextFrameTime = std::chrono::steady_clock::now();

		while (true)
		{
			renderer.Clear();
			renderer.Draw(image, { 200, 100 });
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Blndr::GameWindow::SwapBuffers();
			Blndr::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
}