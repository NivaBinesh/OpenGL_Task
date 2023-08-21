/**
 * @file GLWrapper.h
 * @brief A simple wrapper for OpenGL functions in C++ to implement same functionalities as 'Hello Triangle' example.
 * @author Niva
 */

#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

namespace GLWrapper
{
	/**
	 * @brief Class GLWindow handles the OpenGL window creation
	 */
	class GLWindow
	{
	public:
		/**
		* @brief Construct a GLWindow object.
		*
		* @param width Width of the window.
		* @param height Height of the window.
		* @param title Title of the window.
		*/
		GLWindow(unsigned int width, unsigned int height, const char* title);

		/**
		* @brief Construct a GLWindow object with default values.
		*
		* Default Values : width:800, height:600, title:"My Triangle"
		*/
		GLWindow();

		/**
		* @brief Destroy GLWindow object.
		*/
		~GLWindow();

		/**
		* @brief Checks if the window is closed.
		*
		* @return Returns 1 if the window is closed, 0 otherwise.
		*/
		int isClosed();

		/**
		* @brief Process all input.
		*
		* Query Window(GLFW) for relevant key presses/releases and reacts accordingly.
		*/
		void processInput();

		/**
		 * @brief Swap buffers and poll IO events.
		 *
		 * This function swaps the front and back buffers of the window and
		 * processes IO events such as keys pressed/released, mouse moved, etc.
		 */
		void swapBufferAndPollEvent();

	private:
		GLFWwindow* window;

		/**
		 * @brief Initialize GLFW and configure its properties.
		 */
		void initializeGlfw();

		/**
		 * @brief Create a new window.
		 *
		 * @param width Width of the window.
		 * @param height Height of the window.
		 * @param title Title of the window.
		 * @return GLFWwindow* Pointer to the created GLFW window.
		 */
		GLFWwindow* createWindow(unsigned int width, unsigned int height, const char* title);

		/**
		 * @brief callback function whenever window size changes
		 * (by OS or user resize), this callback function executes.
		 *
		 * @param window Pointer to the window.
		 * @param width New width of the viewport.
		 * @param height New height of the viewport.
		 */
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};

	/**
	 * @brief Class GLShader handles shader functionality
	 */
	class GLShader
	{
	public:
		/**
		 * @brief Construct a GLShader object with a specified color.
		 *
		 * @param r Red component of the color.
		 * @param g Green component of the color.
		 * @param b Blue component of the color.
		 * @param a Alpha component of the color.
		 */
		GLShader(float r, float g, float b, float a);

		/**
		 * @brief Construct a GLShader object with default color(Black).
		 */
		GLShader();

		/**
		 * @brief Destroy the GLShader object.
		 */
		~GLShader();

		/**
		 * @brief To Draw the wireframe polygon
		 */
		void polygon();

		/**
		 * @brief Set the background color.
		 *
		 * @param r Red component of the color.
		 * @param g Green component of the color.
		 * @param b Blue component of the color.
		 * @param a Alpha component of the color.
		 */
		void setBackgroundColor(float r, float g, float b, float a);

		/**
		 * @brief Draw the triangle.
		 */
		void drawTriangle();

	private:
		unsigned int shaderProgram, VAO, VBO;

		/**
		 * @brief Load Glad OpenGL function pointers.
		 */
		void loadGlad();

		/**
		 * @brief Render with the specified colors.
		 *
		 * @param r Red component of the color.
		 * @param g Green component of the color.
		 * @param b Blue component of the color.
		 * @param a Alpha component of the color.
		 */
		void run(float r, float g, float b, float a);

		/**
		 * @brief Define the vertices.
		 * 
		 * set up vertex data (and buffer(s)) and configure vertex attributes.
		 */
		void vertex();
	};
}
