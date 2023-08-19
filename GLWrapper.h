#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>

namespace GLWrapper 
{
	class GLWindow
	{
		//friend class GLShader;
		private:
			//const unsigned int SCR_WIDTH, SCR_HEIGHT;
			GLFWwindow* window;	
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
			void initialize();
			GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);
			void loadGlad();

		public:
			int isClosed();
			void processInput();
			void swapBuff_pollEvent();
			GLWindow(unsigned int width, unsigned int height, const char* title);		//Constructor
			~GLWindow();	//Destructor	

	};

	class GLShader
	{
		private:
			//const char* vertexShaderSource, fragmentShaderSource;
			//unsigned int shaderDeletion(unsigned int vertexShader, unsigned int fragmentShader);
			unsigned int shaderProgram, VAO, VBO;
			void run();
			void vertex();			
			//void render(unsigned int shaderProgram, unsigned int VAO, unsigned int VBO);
		public:
			void polygon();
			void setColor(float R, float G, float B, float O);
			void draw();
			GLShader();		//Constructor
			~GLShader();	//Destructor
	};
}
