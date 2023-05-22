#include "Blndr.h"
#include <iostream>

class Igra : public Blndr::BlndrApp
{
public:
	Igra()
	{
		SetKeyPressedCallback([this](const Blndr::KeyPressed& e) { MyKeyPressedFunc(e); });
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const Blndr::KeyPressed& e)
	{
		if (e.GetKeyCode() == BLNDR_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == BLNDR_KEY_LEFT)
			unit.UpdateXCoord(-20);
		else if (e.GetKeyCode() == BLNDR_KEY_UP)
			unit.UpdateYCoord(20);
		else if (e.GetKeyCode() == BLNDR_KEY_DOWN)
			unit.UpdateYCoord(-20);
	}

private:
	Blndr::Renderer renderer;
	Blndr::Unit unit{ "../Assets/Images/mario.png" {100, 100} };
};

BLNDR_GAME_START(Igra);