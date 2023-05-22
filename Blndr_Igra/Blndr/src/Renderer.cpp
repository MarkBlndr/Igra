#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace Blndr
{
#ifdef BLNDR_OPENGL
		Renderer::Renderer():
			mImplementation(std::unique_ptr<ImplRenderer>{ new OpenGLRenderer }),
			mDefaultShader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" } 
		{}
#else
		#only_OpenGL_is_implemented_at_the_moment
#endif

	void Renderer::Draw(Image& img, Shader& shader, ScreenCoords coords)
	{
		mImplementation->Draw(img, {0, 0, img.GetWidth(), img.GetHeight()}, shader, coords);
	}

	void Renderer::Draw(Image& img, ScreenCoords coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());
		mImplementation->Draw(img, { 0, 0, img.GetWidth(), img.GetHeight() }, mDefaultShader, coords);
	}

	void Renderer::Draw(Image& img, TextureBox texCoords, Shader& shader, ScreenCoords coords)
	{
		mImplementation->Draw(img, texCoords, shader, coords);
	}

	void Renderer::Draw(Image& img, TextureBox texCoords, ScreenCoords coords)
	{
		mDefaultShader.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());
		mImplementation->Draw(img, texCoords, mDefaultShader, coords);
	}

	void Renderer::Draw(Unit& unit, Shader& shader)
	{
		Draw(unit.mImage, shader, unit.mPosition);
	}

	void Renderer::Draw(Unit& unit)
	{
		Draw(unit.mImage, unit.mPosition);
	}

	void Renderer::Clear()
	{
		mImplementation->Clear();
	}
}