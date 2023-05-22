#include "Blndr.h"
#include <iostream>
#include <vector>
#include <ctime>

class Igra : public Blndr::BlndrApp
{
public:
	Igra()
	{
		SetKeyPressedCallback([this](const Blndr::KeyPressed& e) { MyKeyPressedFunc(e); });
		srand(time(NULL));
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(unit);

		if (newStarPosition) {
			starXCoord = rand() % (775 - 25 + 1) + 25;
			starYCoord = rand() % (575 - 25 + 1) + 25;
			star.SetCoords({ starXCoord, starYCoord });
			newStarPosition = false;
			drawStar = true;
		}

		if (drawStar)
		{
			renderer.Draw(star);
		}

		bool scorePlusOne = false;

		if (unit.Overlap(star)) 
		{
			scorePlusOne = true;
			drawStar = false;
			newStarPosition = true;
		}

		if (scorePlusOne)
		{
			score++;
			scorePlusOne = false;
		}
	}

	void MyKeyPressedFunc(const Blndr::KeyPressed& e)
	{
		if (e.GetKeyCode() == BLNDR_KEY_RIGHT)
			if (unit.GetCoords().xCoord + 20 > 700)
				unit.SetCoords({ 700, unit.GetCoords().yCoord });
			else
				unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == BLNDR_KEY_LEFT)
			if (unit.GetCoords().xCoord - 20 < 0)
				unit.SetCoords({ 0, unit.GetCoords().yCoord });
			else
				unit.UpdateXCoord(-20);
		else if (e.GetKeyCode() == BLNDR_KEY_UP)
			if (unit.GetCoords().yCoord + 20 > 500)
				unit.SetCoords({ unit.GetCoords().xCoord, 500 });
			else
				unit.UpdateYCoord(20);
		else if (e.GetKeyCode() == BLNDR_KEY_DOWN)
			if (unit.GetCoords().yCoord - 20 < 0)
				unit.SetCoords({ unit.GetCoords().xCoord, 0 });
			else
				unit.UpdateYCoord(-20);
	}

private:
	Blndr::Renderer renderer;
	Blndr::Unit unit{ "../Assets/Images/yellow.png", {100, 100} };
	Blndr::Unit star{ "../Assets/Images/star.png", {500, 400} };

	int score{ 0 };
	bool drawStar = true;
	bool newStarPosition = true;
	int starXCoord;
	int starYCoord;
};

BLNDR_GAME_START(Igra);