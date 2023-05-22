#pragma once

#include "pch.h"
#include "ImplRenderer.h"

namespace Blndr
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords) override;
		virtual void Clear() override;

	private:
		unsigned int mVBO, mVAO, mEBO;
	};
}