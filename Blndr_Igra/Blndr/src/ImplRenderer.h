#pragma once

#include "Image.h"
#include "Shader.h"
#include "RendererTypes.h"

namespace Blndr
{
	class ImplRenderer
	{
	public:
		virtual void Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords) = 0;
		virtual void Clear() = 0;
	};
}