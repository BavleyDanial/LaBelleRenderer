#include <Application.h>

int main()
{
	LBR::Application* app = new LBR::Application();
	app->Run();
	delete app;

	return 0;
}