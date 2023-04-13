#pragma once

#include "BlndrUtil.h"

namespace Blndr
{
	class BLNDR_API BlndrApp
	{
	public:
		virtual void OnUpdate() = 0;
		void Run();
	private:
	};
}

/*
* Notes:
*	Microsoft compiler wants __declspec(dllexport) - this shows the compiler that this class should be visible to the
*		user in the .dll
*		It should say __declspec(dllimport) when the code is included in the Game project
*		Use macro to get around the problem
*/