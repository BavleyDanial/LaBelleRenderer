#pragma once

#include "Window.h"

namespace LBR {

	class Application
	{
	public:
		Application();
		~Application();

		void Run();
		inline void Close() { m_IsRunning = false; }

		inline static Application& GetApp() { return *s_AppInstance; }
		inline Window& GetWindow() { return *m_Window; }

	private:   
		static Application* s_AppInstance;
		bool m_IsRunning;
	private:
		Window* m_Window = nullptr;
	};

}