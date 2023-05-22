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
	BlndrApp::BlndrApp()
	{
		Blndr::GameWindow::Init();
		Blndr::GameWindow::CreateWindow(800, 600, "Igra");

		SetWindowCloseCallback(std::bind(&BlndrApp::DefaultWindowCloseHandler, this));
	}


	void BlndrApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Blndr::GameWindow::SwapBuffers();
			Blndr::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}

	void BlndrApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callBackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callBackFunc);
	}

	void BlndrApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callBackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callBackFunc);
	}

	void BlndrApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void BlndrApp::DefaultWindowCloseHandler() 
	{
		mGameWindowShouldClose = true;
	}
}