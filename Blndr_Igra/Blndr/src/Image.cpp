#include <pch.h>
#include <Image.h>
#include <OpenGLCode/OpenGLImage.h>

namespace Blndr
{
	Image::Image(const std::string& imageFile)
	{
#ifdef BLNDR_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{ imageFile } };
#else
		#only_OpenGL_is_implemented_at_the_moment
#endif
	}

	Image::Image(std::string&& imageFile)
	{
#ifdef BLNDR_OPENGL
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{ std::move(imageFile) } };
#else
		#only_OpenGL_is_implemented_at_the_moment
#endif
	}

	int Image::GetHeight() const
	{
		return mImplementation->GetHeight();
	}

	int Image::GetWidth() const
	{
		return mImplementation->GetWidth();
	}

	void Image::Activate()
	{
		mImplementation->Activate();
	}
}