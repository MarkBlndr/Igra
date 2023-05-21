#include "pch.h"
#include "Renderer.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace Blndr
{
	Renderer::Renderer()
	{
#ifdef BLNDR_OPENGL
		mImplementation = std::unique_ptr<ImplRenderer>{ new OpenGLRenderer };
#else
		#only_OpenGL_is_implemented_at_the_moment
#endif
	}

	void Renderer::Draw(Image& img, Shader& shader, ScreenCoords coords)
	{
		mImplementation->Draw(img, {0, 0, img.GetWidth(), img.GetHeight()}, shader, coords);
	}

	void Renderer::Draw(Image& img, ScreenCoords coords)
	{
		mImplementation->Draw(img, { 0, 0, img.GetWidth(), img.GetHeight() }, mDefaultShader, coords);
	}

	void Renderer::Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords)
	{
		mImplementation->Draw(img, texCoords, shader, coords);
	}

	void Renderer::Draw(Image& img, TextureBox texCoords, ScreenCoords coords)
	{
		mImplementation->Draw(img, texCoords, mDefaultShader, coords);
	}
}