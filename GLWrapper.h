#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>

namespace GLWrapper 
{
	class GLWindow
	{
		private:
			//const unsigned int SCR_WIDTH, SCR_HEIGHT;
			GLFWwindow* window;
			
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
			
			void initialize();
			GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);
			void loadGlad();

		public:
			void run();
			GLWindow(unsigned int width, unsigned int height, const char* title);		//Constructor
			~GLWindow();	//Destructor	

	};
	//TODO implement other classes
}
