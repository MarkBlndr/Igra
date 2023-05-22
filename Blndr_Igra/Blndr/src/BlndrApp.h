#pragma once

#include "pch.h"
#include "BlndrUtil.h"
#include "BlndrEvents.h"

constexpr int FPS{ 60 };

namespace Blndr
{
	class BLNDR_API BlndrApp
	{
	public:
		BlndrApp();

		virtual void OnUpdate() = 0;
		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callBackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callBackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);



	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;

		bool mGameWindowShouldClose{false};
		void DefaultWindowCloseHandler();
	};
}