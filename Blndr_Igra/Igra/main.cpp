#include "Blndr.h"
#include <iostream>

class Igra : public Blndr::BlndrApp
{
public:
	Igra()
	{
		Blndr::GameWindow::Init();
		Blndr::GameWindow::CreateWindow(800, 600, "Igra");
	}

	void Run() 
	{
		while (true)
		{
			//std::cout << "Blndr running\n";
			OnUpdate();
		}
	}

	virtual void OnUpdate() override
	{
		Blndr::GameWindow::SwapBuffers();
		Blndr::GameWindow::PollEvents();
	}
};

BLNDR_GAME_START(Igra);