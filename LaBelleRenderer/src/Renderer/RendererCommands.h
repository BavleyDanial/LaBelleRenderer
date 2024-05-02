#pragma once

#include <iostream>
#include <glm/glm.hpp>

namespace LBR {

	class RendererCommands
	{
	public:
		virtual void Init() = 0;

		virtual void ClearColor(const glm::vec4& color) = 0;
		virtual void DrawIndexed() = 0;
	};
}