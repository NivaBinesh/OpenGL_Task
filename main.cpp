#include<iostream>
#include "GLWrapper.h"

int main()
{
	GLWrapper::GLWindow w(800, 600, "My_Triangle");	//Specifies the dimentions and title of the window
	GLWrapper::GLShader s;
	// uncomment this call to draw in wireframe polygons.
	//s.polygon();
	while (!w.isClosed())
	{
		w.processInput();
		s.setColor(0.2f, 0.3f, 0.3f, 1.0f); //Set prederred colors in terms of R,G,B as first 3 parameters
		s.draw();
		w.swapBuff_pollEvent();
	}
	return 0;
}
  