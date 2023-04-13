#pragma once

#ifdef BLNDR_WINDOWS // For all windows projects, include these definitions
#ifdef BLNDR_LIB
#define BLNDR_API __declspec(dllexport)
#else
#define BLNDR_API __declspec(dllimport)
#endif

#else
#define BLNDR_API
#endif

#define BLNDR_GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}