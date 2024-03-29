#pragma once

#include "pch.h"
#include "BlndrUtil.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"
#include "RendererTypes.h"
#include "Unit.h"

namespace Blndr
{
	class BLNDR_API Renderer 
	{
	public:
		Renderer();

		void Draw(Image& img, Shader& shader, ScreenCoords coords);
		void Draw(Image& img, ScreenCoords coords);

		void Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords);
		void Draw(Image& img, TextureBox texCoords, ScreenCoords coords);

		void Draw(Unit& unit, TextureBox texCoords);
		void Draw(Unit& unit, Shader& shader);
		void Draw(Unit& unit);

		void Clear();

	private:
		std::unique_ptr<ImplRenderer> mImplementation{ nullptr };
		Shader mDefaultShader;
	};

}