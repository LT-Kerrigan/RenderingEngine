#pragma comment(lib, "nclgl.lib")

#include "./GraphicsFramework/window.h"
#include "Renderer.h"

int main()	{
	Window w("01_HelloWorld_Of_OpenGL", 800 , 600, false);

	if(!w.HasInitialised()) {
		return -1;
	}
	
	Renderer renderer(w);
	if(!renderer.HasInitialised()) {
		return -1;
	}

	while(w.UpdateWindow()  && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)){
		renderer.RenderScene();
	}

	return 0;
}