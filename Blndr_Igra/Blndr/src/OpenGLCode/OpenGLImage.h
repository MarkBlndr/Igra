#pragma once

#include "../pch.h"
#include "../ImplImage.h"

namespace Blndr
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imageFile);
		~OpenGLImage();

		virtual void Activate() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
	
	private:
		unsigned int mImage{ 0 };
		int mHeight{ 0 };
		int mWidth{ 0 };
	};
}