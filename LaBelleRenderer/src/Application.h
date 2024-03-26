#pragma once

#include <GLFW/glfw3.h>

namespace LBR {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();

	private:
		GLFWwindow* m_Window = nullptr;
		static Application* s_AppInstance;
	};

}