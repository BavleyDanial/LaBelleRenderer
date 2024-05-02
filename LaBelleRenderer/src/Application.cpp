#include <Application.h>

#include <Core.h>
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <imgui.h>
#include <Renderer/Renderer.h>
#include <GUI/ImGui/imgui_impl_glfw.h>
#include <GUI/ImGui/imgui_impl_opengl3.h>

#include <vector>

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
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
		const char* fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(0.1f, 0.3f, 0.4f, 1.0f);\n"
			"}\n\0";

		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// link shaders
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f
		};

		std::vector<uint32_t> indices = {
			0, 1, 2,
			2, 3, 0
		};

		uint32_t VAO;
		glCreateVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		uint32_t vertexBuffer;
		glCreateBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

		uint32_t indexBuffer;
		glCreateBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indices.size(), indices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
		glEnableVertexAttribArray(0);

		while (m_IsRunning)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			m_Renderer->ClearColor(glm::vec4(0.1f, 0.1f, 0.1f, 1.0f));

			glUseProgram(shaderProgram);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			m_Window->SwapBuffers();
			m_Window->PollEvents();
		}
	}

}