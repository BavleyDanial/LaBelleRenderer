#include <Application.h>

#include <Core.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <imgui.h>
#include <Renderer/Renderer.h>
#include <GUI/ImGui/imgui_impl_glfw.h>
#include <GUI/ImGui/imgui_impl_opengl3.h>

namespace LBR {

	Application* Application::s_AppInstance = nullptr;

	Application::Application()
	{
		ASSERT(!s_AppInstance, "Application already has an instance!");
		s_AppInstance = this;
		m_IsRunning = true;

		WindowSpecifications specs;
		specs.Width = 1280;
		specs.Height = 720;
		specs.Title = "Title";
		specs.IsFullScreen = false;
		specs.IsVSync = true;

		m_Window = new Window(specs);
		m_Renderer = new Renderer();
	}

	Application::~Application()
	{
		if (m_Renderer)
			delete m_Renderer;
		if (m_Window)
			delete m_Window;
	}

	void Application::Run()
	{
		glm::vec4 v(0.2, 0.2, 0.2, 1);

		while (m_IsRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			m_Renderer->ClearColor(v);

			m_Window->SwapBuffers();
			m_Window->PollEvents();
		}
	}

}