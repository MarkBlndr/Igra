#pragma once

#include "BlndrUtil.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"

namespace Blndr
{
	class BLNDR_API Renderer 
	{
	public:
		Renderer();

		void Draw(Image& img, Shader& shader, int xCoord, int ycoord);
		void Draw(Image& img, int xCoord, int ycoord);

		void Draw(Image& img, float xTexCoord, float yTexCoord, Shader& shader, int xCoord, int ycoord);
		void Draw(Image& img, float xTexCoord, float yTexCoord, int xCoord, int ycoord);

	private:
		ImplRenderer* mImplementation{ nullptr };
	};

}