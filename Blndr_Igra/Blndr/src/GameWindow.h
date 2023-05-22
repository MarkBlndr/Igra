#pragma once

#include "pch.h"
#include "BlndrUtil.h"
#include "WindowImplementation.h"
#include "BlndrEvents.h"

namespace Blndr
{
	class BLNDR_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int GetWidth();
		static int GetHeight();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		~GameWindow();

	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };

	};
}