#pragma once
#include "BlndrUtil.h"

namespace Blndr
{
	class BLNDR_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class BLNDR_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;
	};

	class BLNDR_API WindowClosed
	{

	};
}