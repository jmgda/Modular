cmake_minimum_required(VERSION 3.8)

project("Modular")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY 
	${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY 
	${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME})

set(project_headers 
	Source/Modular.h 
	Source/Renderer.h 
	Source/Mesh.h 
	Source/Shader.h 
	Source/Camera.h 
	Vendor/glad/glad.h 
	Vendor/glad/khrplatform.h
	Vendor/stb_image/stb_image.h)

set(project_sources 
	Source/Renderer.cpp 
	Source/Mesh.cpp 
	Source/Shader.cpp 
	Source/Camera.cpp 
	Vendor/glad/glad.c 
	Vendor/stb_image/stb_image.cpp)

add_library(${PROJECT_NAME} STATIC
	${project_headers} 
	${project_sources})

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_HOME_DIRECTORY}/${PROJECT_NAME}/Source 
	${CMAKE_HOME_DIRECTORY}/${PROJECT_NAME}/Vendor)