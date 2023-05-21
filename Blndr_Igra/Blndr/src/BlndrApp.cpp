#include "pch.h"
#include "BlndrApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Shader.h"
#include "Image.h"

namespace Blndr
{
	void BlndrApp::Run()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			BLNDR_ERROR("Failed to initialize GLAD");
			return;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		float vdata[] = {
			200.0f, 100.0f, 0.0, 0.0,
			200.0f, 200.0f, 0.0, 1.0,
			300.0f, 200.0f, 1.0, 1.0,
			300.0f, 100.0f, 1.0, 0.0
		};

		int edata[] = {
			0, 1, 3,
			1, 2, 3
		};

		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vdata), vdata, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(edata), edata, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(0));
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
		glEnableVertexAttribArray(1);


		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };
		sProgram.Pass2FloatValues("screenSize", GameWindow::GetWidth(), GameWindow::GetHeight());

		Image sImage{ "../Assets/Images/test.png" };

		while (true)
		{
			glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glBindVertexArray(VAO);
			sProgram.Activate();
			sImage.Activate();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			OnUpdate();
		}
	}
}