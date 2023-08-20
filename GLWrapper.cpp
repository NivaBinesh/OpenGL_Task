/**
* @file GLWrapper.cpp
* @brief Implementation of GLWrapper.
* @author Niva
*/

#include "GLWrapper.h"

namespace GLWrapper
{
	//---------------------Class GLWindow implementations-----------------------------

	GLWindow::GLWindow(unsigned int width, unsigned int height, const char* title)
	{
		initializeGlfw();
		createWindow(width, height, title);
	}
	
	GLWindow::GLWindow()
	{
		initializeGlfw();
		createWindow(800, 600, "My Triangle");
	}

	int GLWindow::isClosed()
	{
		return glfwWindowShouldClose(window);
	}

	void GLWindow::processInput()
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
	}

	void GLWindow::swapBufferAndPollEvent()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	void GLWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

	void GLWindow::initializeGlfw()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	GLFWwindow* GLWindow::createWindow(unsigned int width, unsigned int height, const char* title)
	{
		window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			throw std::runtime_error("Failed to create GLFW window");
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	}

	GLWindow::~GLWindow()
	{
		// glfw: terminate, clearing all previously allocated GLFW resources
		glfwTerminate();
	}

	//---------------------Class GLShader implementations-----------------------------

	GLShader::GLShader(float r, float g, float b, float a)
	{
		loadGlad();
		run(r,g,b,a);
		vertex();
	}

	GLShader::GLShader()
	{
		loadGlad();
		run(0.0,0.0,0.0,1.0);
		vertex();
	}
	
	void GLShader::loadGlad()
	{
		// glad: load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			throw std::runtime_error("Failed to initialize GLAD");
		}
	}

	void GLShader::setColor(float R, float G, float B, float O)
	{
		// render
		glClearColor(R,G,B,O);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void GLShader::drawTriangle()
	{
		// draw our first triangle
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);

		// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// glBindVertexArray(0); // no need to unbind it every time 
	}

	void GLShader::run(float r, float g,float b, float o)
	{
		const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";

		std::string temp = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(" + std::to_string(r) + "f, " + std::to_string(g) + "f, " + std::to_string(b) + "f, " + std::to_string(o) + "f);\n"
			"}\n\0";

		const char* fragmentShaderSource = temp.c_str();

		// vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			throw std::runtime_error("Failed to compile Vertex Shader"+ std::string(infoLog));
		}
		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			throw std::runtime_error("Failed to compile Fragment Shader" + std::string(infoLog));
		}
		// link shaders
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		// check for linking errors
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
			throw std::runtime_error("Failed to link Vertex and Fragment Shaders" + std::string(infoLog));
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void GLShader::vertex()
	{		
		float vertices[] = 
		{
			-0.5f, -0.5f, 0.0f, // left  
			 0.5f, -0.5f, 0.0f, // right 
			 0.0f,  0.5f, 0.0f  // top   
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);		
	}

	GLShader::~GLShader()
	{
		// optional: de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
		glDeleteProgram(shaderProgram);
	}

	void GLShader::polygon()
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}