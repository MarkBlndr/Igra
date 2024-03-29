#pragma once

#include "BlndrUtil.h"
#include "Image.h"
#include "RendererTypes.h"


namespace Blndr
{
	class BLNDR_API Unit
	{
	public:
		Unit(const std::string & image, ScreenCoords coords, int texWidth, int texHeight);
		Unit(std::string&& image, ScreenCoords coords, int texWidth, int texHeight);

		int GetWidth() const;
		int GetHeight() const;

		ScreenCoords GetCoords() const;
		void SetCoords(ScreenCoords newCoords);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);

		bool Overlap(const Unit& b) const;

	private:
		Image mImage;
		ScreenCoords mPosition;
		int mTexWidth;
		int mTexHeight;

		friend class Renderer;
		friend bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	bool UnitsOverlap(const Unit& a, const Unit& b);
}