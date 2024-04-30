#pragma once

#include <Renderer/RendererCommands.h>
#include <Platform/OpenGL/OpenGLCommands.h>

#include <glm/glm.hpp>

namespace LBR {

	enum class RendererAPI
	{
		UNKNOWN = 0,
		SOFTWARE,
		OPENGL,
		VULKAN,
		D3D12,
	};

	class Renderer
	{
	public:
		Renderer(RendererAPI api = RendererAPI::OPENGL);
		~Renderer();

		void SetRendererAPI(RendererAPI api);

		RendererAPI GetRendererAPI() { return m_RendererAPI; }

		void ClearColor(const glm::vec4& color);
		void DrawIndexed();

	private:
		RendererAPI m_RendererAPI = RendererAPI::UNKNOWN;
		static RendererCommands* s_RendererCommands;
		static Renderer* s_RendererInstance;
	};
}