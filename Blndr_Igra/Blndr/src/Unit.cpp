#include "pch.h"
#include "Unit.h"

namespace Blndr
{
	Unit::Unit(const std::string& image, ScreenCoords coords) :
		mImage(image), mPosition(coords) {};

	Unit::Unit(std::string&& image, ScreenCoords coords) : mImage(std::move(image)), mPosition(coords) {};

	int Unit::GetWidth() const 
	{
		return mImage.GetWidth();
	}

	int Unit::GetHeight() const
	{
		return mImage.GetHeight();
	}

	ScreenCoords Unit::GetCoords() const
	{
		return mPosition;
	}

	void Unit::SetCoords(ScreenCoords newCoords)
	{
		mPosition = newCoords;
	}

	void Unit::UpdateXCoord(int amount)
	{
		mPosition.xCoord += amount;
	}

	void Unit::UpdateYCoord(int amount)
	{
		mPosition.yCoord += amount;
	}

	bool Unit::Overlap(const Unit& b) const
	{
		int left_a{ mPosition.xCoord };
		int right_a{ mPosition.xCoord + mImage.GetWidth() };

		int left_b{ b.mPosition.xCoord };
		int right_b{ b.mPosition.xCoord + b.mImage.GetWidth() };

		bool x_intersection{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b) };

		int bot_a{ mPosition.yCoord };
		int top_a{ mPosition.yCoord + mImage.GetHeight() };

		int bot_b{ b.mPosition.yCoord };
		int top_b{ b.mPosition.yCoord + b.mImage.GetHeight() };

		bool y_intersection{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

		return x_intersection and y_intersection;
		
	}

	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mPosition.xCoord };
		int right_a{ a.mPosition.xCoord + a.mImage.GetWidth() };

		int left_b{ b.mPosition.xCoord };
		int right_b{ b.mPosition.xCoord + b.mImage.GetWidth() };

		bool x_intersection{ (left_a <= left_b and left_b <= right_a) or (left_b <= left_a and left_a <= right_b)};

		int bot_a{ a.mPosition.yCoord };
		int top_a{ a.mPosition.yCoord + a.mImage.GetHeight() };

		int bot_b{ b.mPosition.yCoord };
		int top_b{ b.mPosition.yCoord + b.mImage.GetHeight() };

		bool y_intersection{ (bot_a <= bot_b and bot_b <= top_a) or (bot_b <= bot_a and bot_a <= top_b) };

		return x_intersection and y_intersection;
	}
	
}