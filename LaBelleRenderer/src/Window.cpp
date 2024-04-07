#include "Window.h"

#include "Application.h"

#include <iostream>

namespace LBR {

	bool Window::s_GLFWInitialized = false;

	Window::Window(const WindowSpecifications& specs)
		:m_WindowSpecs(specs)
	{
		Init();
	}

	void Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Could not initialize GLFW!!\n";
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_WindowSpecs.Width, m_WindowSpecs.Height, m_WindowSpecs.Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			std::cout << "Couldn't create window!!\n";
			return;
		}
		glfwMakeContextCurrent(m_Window);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			Window windowRef = Application::GetApp().GetWindow();
			windowRef.Shutdown();
		});
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::SwapBuffers()
	{
		glfwSwapBuffers(m_Window);
	}
	
	void Window::Shutdown()
	{
		Application::GetApp().Close();

		if (m_Window)
			glfwDestroyWindow(m_Window);
	}

	void Window::SetWidth(uint32_t width)
	{

	}

	void Window::SetHeight(uint32_t height)
	{

	}

	void Window::SetVSync(bool enabled)
	{

	}

	void Window::SetFullScreen(bool enabled)
	{

	}

}