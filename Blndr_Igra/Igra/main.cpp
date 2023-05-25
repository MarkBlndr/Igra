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
		srand(std::time(NULL));
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();

		if (!startGame)
		{
			renderer.Draw(splash);
		}
		else
		{
			if (clock != 0)
			{
				renderer.Draw(background);
				renderer.Draw(timeSign, { 0, 0, 300, 45 });

				//Render clock
				timeTexX1 = (clock / 10) * 45;
				timeTexX2 = (clock % 10) * 45;
				renderer.Draw(num1, { timeTexX1, 0, 45, 45 });
				renderer.Draw(num2, { timeTexX2, 0, 45, 45 });

				timeFrameCounter -= 1;

				if (timeFrameCounter == 0)
				{
					clock--;
					timeFrameCounter = 45;
				}

				renderer.Draw(robot);

				if (newDiskPosition) {
					starXCoord = rand() % (750 - 50 + 1) + 25;
					starYCoord = rand() % (550 - 50 + 1) + 25;
					disk.SetCoords({ starXCoord, starYCoord });
					newDiskPosition = false;
				}

				diskFrameCounter -= 1;

				if (diskFrameCounter == 0)
				{
					diskTexX += 25;
					if (diskTexX > 125)
						diskTexX = 0;

					diskFrameCounter = 5;
				}

				renderer.Draw(disk, { diskTexX, 75, 25, 25 });

				bool scorePlusOne = false;

				if (robot.Overlap(disk))
				{
					scorePlusOne = true;
					newDiskPosition = true;
				}

				if (scorePlusOne)
				{
					score++;
					scorePlusOne = false;
				}
			}
			else 
			{
				if (score > 99)
					score = 99;
				renderer.Draw(scoreScreen);
				timeTexX1 = (score / 10) * 45;
				timeTexX2 = (score % 10) * 45;
				renderer.Draw(num3, { timeTexX1, 0, 45, 45 });
				renderer.Draw(num4, { timeTexX2, 0, 45, 45 });
			}
		}
	}

	void MyKeyPressedFunc(const Blndr::KeyPressed& e)
	{
		if (e.GetKeyCode() == BLNDR_KEY_ENTER) {
			if (clock <= 0)
				clock = 15;
			if (clock == 15)
				score = 0;
			startGame = true;
		}
		else if (e.GetKeyCode() == BLNDR_KEY_RIGHT)
		{
			if (robot.GetCoords().xCoord + 20 > 700)
				robot.SetCoords({ 700, robot.GetCoords().yCoord });
			else
				robot.UpdateXCoord(20);
		}
		else if (e.GetKeyCode() == BLNDR_KEY_LEFT)
		{
			if (robot.GetCoords().xCoord - 20 < 0)
				robot.SetCoords({ 0, robot.GetCoords().yCoord });
			else
				robot.UpdateXCoord(-20);
		}
		else if (e.GetKeyCode() == BLNDR_KEY_UP)
		{
			if (robot.GetCoords().yCoord + 20 > 500)
				robot.SetCoords({ robot.GetCoords().xCoord, 500 });
			else
				robot.UpdateYCoord(20);
		}
		else if (e.GetKeyCode() == BLNDR_KEY_DOWN)
		{
			if (robot.GetCoords().yCoord - 20 < 0)
				robot.SetCoords({ robot.GetCoords().xCoord, 0 });
			else
				robot.UpdateYCoord(-20);
		}
	}

private:
	Blndr::Renderer renderer;

	Blndr::Unit background{ "../Assets/Images/Arena.png", { 0,0 }, 0, 0 };
	Blndr::Unit splash{ "../Assets/Images/SplashScreen.png", { 0,0 }, 0, 0 };
	Blndr::Unit scoreScreen{ "../Assets/Images/ScoreScreen.png", { 0,0 }, 0, 0 };

	Blndr::Unit timeSign{ "../Assets/Images/Time.png", {250, 25}, 0, 0 };

	// clock numbers
	Blndr::Unit num1{ "../Assets/Images/Numbers.png", { 400,25 }, 0, 0 };
	Blndr::Unit num2{ "../Assets/Images/Numbers.png", { 445,25 }, 0, 0 };

	// score numbers
	Blndr::Unit num3{ "../Assets/Images/Numbers.png", { 445,327 }, 0, 0 };
	Blndr::Unit num4{ "../Assets/Images/Numbers.png", { 490,327 }, 0, 0 };

	Blndr::Unit robot{ "../Assets/Images/Robot.png", {100, 100}, 100, 100 };
	Blndr::Unit disk{ "../Assets/Images/Disk.png", {500, 400}, 25, 25 };

	bool startGame{ false };

	int diskFrameCounter{ 5 };
	int diskTexX{ 0 };

	int timeFrameCounter{ 45 };
	int clock{ 15 };

	int timeTexX1{ 0 };
	int timeTexX2{ 0 };

	int score{ 0 };
	bool newDiskPosition = true;
	int starXCoord;
	int starYCoord;
};

BLNDR_GAME_START(Igra);