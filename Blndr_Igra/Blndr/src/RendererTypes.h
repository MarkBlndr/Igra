#pragma once

namespace Blndr 
{
	struct TextureBox
	{
		int xTexCoord{ 0 };
		int yTexCoord{ 0 };
		int texWidth{ 0 };
		int texHeight{ 0 };

		TextureBox(int xOnPicture, int yOnPicture, int boxWidth, int boxHeight) :
			xTexCoord(xOnPicture), yTexCoord(yOnPicture), texWidth(boxWidth), texHeight(boxHeight) {};
	};

	struct ScreenCoords
	{
		int xCoord{ 0 };
		int yCoord{ 0 };

		ScreenCoords(int x, int y) : xCoord(x), yCoord(y) {};
	};
}