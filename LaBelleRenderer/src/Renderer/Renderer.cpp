#include "Renderer.h"

#include <cassert>

namespace LBR {

	Renderer* Renderer::s_RendererInstance = nullptr;
	RendererCommands* Renderer::s_RendererCommands = nullptr;

	Renderer::Renderer(RendererAPI api)
	{
		if (s_RendererInstance)
			assert("There is already an instance of renderer!");

		s_RendererInstance = this;
		SetRendererAPI(api);
	}

	Renderer::~Renderer()
	{
		if (s_RendererCommands)
			delete s_RendererCommands;

		s_RendererInstance = nullptr;
	}

	void Renderer::SetRendererAPI(RendererAPI api)
	{
		switch (api)
		{
		case RendererAPI::UNKNOWN:
			break;
		case RendererAPI::OPENGL:
			if (s_RendererCommands)
				delete s_RendererCommands;
			s_RendererCommands = new OpenGLCommands;
			break;
		case RendererAPI::VULKAN:
			break;
		default:
			break;
		}

		m_RendererAPI = api;

		s_RendererCommands->Init();
	}

	void Renderer::DrawIndexed()
	{
		s_RendererCommands->DrawIndexed();
	}

	void Renderer::ClearColor(float r, float g, float b, float a)
	{
		s_RendererCommands->ClearColor(r, g, b, a);
	}
}