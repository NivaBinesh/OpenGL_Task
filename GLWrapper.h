#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>

namespace GLWrapper 
{
	class GLWindow
	{
		friend class GLShader;
		private:
			//const unsigned int SCR_WIDTH, SCR_HEIGHT;
			GLFWwindow* window;
			
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
			
			void initialize();
			GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);
			void loadGlad();

		public:
			
			GLWindow(unsigned int width, unsigned int height, const char* title);		//Constructor
			~GLWindow();	//Destructor	

	};

	class GLShader
	{
		private:
			//const char* vertexShaderSource, fragmentShaderSource;
			//unsigned int shaderDeletion(unsigned int vertexShader, unsigned int fragmentShader);
			void run();
		public:
			GLShader();		//Constructor
			~GLShader();	//Destructor
	};
	//TODO implement other classes
}
