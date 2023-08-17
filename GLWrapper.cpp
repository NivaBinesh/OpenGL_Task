#include "GLWrapper.h"
	
namespace GLWrapper
{
	GLWindow::GLWindow(unsigned int width, unsigned int height, const char* title)
	{
		initialize();
		createWindow(width, height, title);
		loadGlad();
	}
	
	void GLWindow::initialize()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void GLWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

	// glfw window creation

	GLFWwindow* GLWindow::createWindow(unsigned int width, unsigned int height, const char* title)
	{
		GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			//return -1;
			throw std::runtime_error("Failed to create GLFW window");
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	}
	
	// glad: load all OpenGL function pointers

	void GLWindow::loadGlad()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			//return -1;
			throw std::runtime_error("Failed to initialize GLAD");
		}
	}
	GLWindow::~GLWindow()
	{
		glfwTerminate();
	}
}
