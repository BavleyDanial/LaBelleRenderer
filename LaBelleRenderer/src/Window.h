#pragma once

#include <GLFW/glfw3.h>

#include <cstdint>
#include <string>

namespace LBR {

	struct WindowSpecifications
	{
		uint32_t Width = 1280;
		uint32_t Height = 720;
		std::string Title = "Title";
		bool IsVSync = true;
		bool IsFullScreen = true;
	};

	class Window
	{
	public:
		Window(const WindowSpecifications& specs);

		void Init();
		void PollEvents();
		void SwapBuffers();
		void Shutdown();

		void SetWidth(uint32_t width);
		void SetHeight(uint32_t height);

		void SetVSync(bool enabled);
		void SetFullScreen(bool enabled);

		inline uint32_t GetWidth() const { return m_WindowSpecs.Width; }
		inline uint32_t GetHeight() const { return m_WindowSpecs.Height; }

		inline bool IsVSync() const { return m_WindowSpecs.IsVSync; }
		inline bool IsFullScreen() const { return m_WindowSpecs.IsFullScreen; }

		inline GLFWwindow* GetNativeWindow() { return m_Window; }
	private:
		WindowSpecifications m_WindowSpecs;
		GLFWwindow* m_Window = nullptr;
		static bool s_GLFWInitialized;
	};

}
