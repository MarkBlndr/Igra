#include "pch.h"
#include "BlndrEvents.h"

namespace Blndr
{
	KeyPressed::KeyPressed(int kCode) : mKeyCode(kCode) {};
	
	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int kCode) : mKeyCode(kCode) {};

	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}