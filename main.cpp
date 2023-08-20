/**
* @file main.cpp
* @brief Application using GLWrapper - initializes the GLFW window, sets up shaders, and draws the triangle.
* @author Niva
*/

#include<iostream>
#include "GLWrapper.h"

int main()
{
	//GLWrapper::GLWindow w;	//Creates default GLWindow Object (with the dim. W*H:800*600 and title: "My Triangle")
	GLWrapper::GLWindow w(800, 600, "My_Triangle");	//Creates GLWindow Object with specified dimensions and title

	//GLWrapper::GLShader s;	//Creates a default GLShader object for a Black triangle
	GLWrapper::GLShader s(0.9,0.2,0.5,1.0);	//Creates Shader Object with preferred RGB and Alpha values
	
	//s.polygon();	//Uncomment this call to draw in wireframe polygons

	while (!w.isClosed())
	{
		w.processInput();
		s.setColor(1.0f, 1.0f, 1.0f, 1.0f); //Set preferred background color in terms of R,G,B as first 3 parameters
		s.drawTriangle();
		w.swapBufferAndPollEvent();
	}
	return 0;
}
  