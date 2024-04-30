#pragma once

#include <glad/glad.h>
#include <Renderer/RendererCommands.h>

namespace LBR {

	class OpenGLCommands : public RendererCommands
	{
		virtual void Init() override
		{
			if (!gladLoadGL())
			{
				std::cout << "glad isn't initialized!" << std::endl;
			}
		}

		virtual void ClearColor(float r, float g, float b, float a) override
		{
			glClearColor(r, g, b, a);
		}

		virtual void DrawIndexed() override
		{
			std::cout << "Drew something in OpenGL!" << std::endl;
		}
	};

}