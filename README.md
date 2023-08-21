# GLWrapper

This is a simple C++ wrapper to implement OpenGL functionalities to encapsulate OpenGL functionalities and achieve the same results as in the ["Hello Triangle" example](https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/2.1.hello_triangle/hello_triangle.cpp).

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Documentation](#documentation)
- [Installation](#installation)
- [Output](#output)

## Introduction

The code is divided into three files:
- `main.cpp`: Initializes the GLFW window, sets up shaders, and runs the rendering loop.
- `GLWrapper.h`: Contains the C++ wrapper classes for handling window creation and shader functionalities.
- `GLWrapper.cpp`: Implements the methods defined in the `GLWrapper.h` header.

## Features

- Window creation.
- Shader compilation and linking.
- Rendering a colored triangle.

## Prerequisites

Before you start, make sure you have the following installed on your system:

- C++
- OpenGL
- [GLFW](https://www.glfw.org/)
- [GLAD](https://glad.dav1d.de/)

## Documentation

For the supported list of functions and their usage, please refer to the [`GLWrapper.h`](GLWrapper.h) header file. This file contains brief documentation for the classes and functions used.

## Installation

1. Clone this repository to your local machine using:
```
git clone https://github.com/NivaBinesh/OpenGL_Task
```
2. Build the application using your C++ compiler and run the executable

For example, using g++:
```
g++ main.cpp GLWrapper.cpp glad.c -o OpenGLApp -lglfw -ldl

./OpenGLApp
```

## Output

1.Sample output with customized window and object color.

![`Output 1`](outputs/output.PNG)

2.Sample output with wireframe polygon enabled.

![`Output 2`](outputs/Polygon.PNG)