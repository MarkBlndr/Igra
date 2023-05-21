#pragma once
#include "ImplRenderer.h"

namespace Blndr
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& img, Renderer::TextureBox texCoords, Shader& shader, Renderer::ScreenCoords coords) override;

	private:
		unsigned int mVBO, mVAO, mEBO;
	};
}