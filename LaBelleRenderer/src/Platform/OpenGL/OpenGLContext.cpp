#include "OpenGLContext.h"

#include <glad/glad.h>

void OpenGLContext::CreateContext()
{
	if (!gladLoadGL())
	{
		static_assert("Couldn't load OpenGL!");
	}
}
