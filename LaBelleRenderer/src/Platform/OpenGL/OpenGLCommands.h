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

		virtual void ClearColor(const glm::vec4& color) override
		{
			glClearColor(color.r, color.g, color.b, color.a);
		}

		virtual void DrawIndexed() override
		{
			std::cout << "Drew something in OpenGL!" << std::endl;
		}
	};

}