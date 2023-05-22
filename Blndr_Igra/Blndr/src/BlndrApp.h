#pragma once

#include "pch.h"
#include "BlndrUtil.h"

constexpr int FPS{ 60 };

namespace Blndr
{
	class BLNDR_API BlndrApp
	{
	public:
		virtual void OnUpdate() = 0;
		void Run();
	private:
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}