#include "Blndr.h"
#include <iostream>

class Igra : public Blndr::BlndrApp
{
public:
	Igra()
	{
		//Blndr::GameWindow::Init();
		//Blndr::GameWindow::CreateWindow(800, 600, "Test Name");
	}

	virtual void OnUpdate() override
	{
		std::cout << "Game is running!" << std::endl;

		//Blndr::GameWindow::SwapBuffers();
		//Blndr::GameWindow::PollEvents();
	}
};

BLNDR_GAME_START(Igra);