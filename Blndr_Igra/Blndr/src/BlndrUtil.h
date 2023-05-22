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

#if BLNDR_DEBUG==2
	#define BLNDR_LOG(x) std::cout << "LOG: " << x << std::endl;
	#define BLNDR_ERROR(x) std::cout << "ERROR: " << x << std::endl;
#elif BLNDR_DEBUG==1
	#define BLNDR_LOG(x);
	#define BLNDR_ERROR(x) std::cout << "ERROR: " << x << std::endl;
#else
	#define BLNDR_LOG(x);
	#define BLNDR_ERROR(x);
#endif