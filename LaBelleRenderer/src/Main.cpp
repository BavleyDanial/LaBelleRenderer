#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW!!\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


	GLFWwindow* window;
	window = glfwCreateWindow(1280, 720, "Testing", nullptr, nullptr);
	if (!window)
	{
		std::cout << "Couldn't create window!!\n";
		return -2;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}