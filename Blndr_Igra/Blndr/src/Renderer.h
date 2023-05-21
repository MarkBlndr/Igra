#pragma once

#include "pch.h"
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

		void Draw(Image& img, Shader& shader, ScreenCoords coords);
		void Draw(Image& img, ScreenCoords coords);

		void Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords);
		void Draw(Image& img, TextureBox texCoords, ScreenCoords coords);

	private:
		std::unique_ptr<ImplRenderer> mImplementation{ nullptr };
		Shader mDefaultShader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
	};

}