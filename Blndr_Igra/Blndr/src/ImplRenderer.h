#pragma once

#include "Renderer.h"

namespace Blndr
{
	class ImplRenderer
	{
	public:
		virtual void Draw(Image& img, Renderer::TextureBox texCoords, Shader& shader, Renderer::ScreenCoords coords) = 0;
	};
}