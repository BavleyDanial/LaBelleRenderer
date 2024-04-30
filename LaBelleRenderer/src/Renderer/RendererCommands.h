#pragma once

#include <iostream>

namespace LBR {

	class RendererCommands
	{
	public:
		virtual void Init() = 0;
		virtual void ClearColor(float r, float g, float b, float a) = 0;
		virtual void DrawIndexed() = 0;
	};
}