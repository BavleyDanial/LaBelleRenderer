#pragma once

#include <Core.h>

#include <Platform/OpenGL/OpenGLContext.h>

enum class GraphicsAPI
{
	NONE = 0,
	OPENGL,
	VULKAN,
	D3D12
};

class RendererContext
{
public:
	static void CreateContext(GraphicsAPI api)
	{
		switch (api)
		{
		case GraphicsAPI::NONE:
			ASSERT(false, "There is no graphics API selected!");
			break;
		case GraphicsAPI::OPENGL:
			OpenGLContext::CreateContext();
			m_API = GraphicsAPI::OPENGL;
			break;
		case GraphicsAPI::VULKAN:
			ASSERT(false, "There is no Vulkan API Implementation yet!");
			break;
		case GraphicsAPI::D3D12:
			ASSERT(false, "There is no D3D12 API Implementation yet!");
			break;
		}
	}

	static GraphicsAPI GetCurrentAPI() { return m_API; }
private:
	static GraphicsAPI m_API;
};

GraphicsAPI RendererContext::m_API = GraphicsAPI::NONE;
