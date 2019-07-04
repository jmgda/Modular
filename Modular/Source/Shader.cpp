#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>

Modular::Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	vertexFile.open(vertexPath);
	fragmentFile.open(fragmentPath);
	std::stringstream vertexStream, fragmentStream;

	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();

	vertexFile.close();
	fragmentFile.close();

	std::string vertexCode;
	std::string fragmentCode;

	vertexCode = vertexStream.str();
	fragmentCode = fragmentStream.str();

	const char* c_VertexCode = vertexCode.c_str();
	const char* c_FragmentCode = fragmentCode.c_str();

	unsigned int vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &c_VertexCode, NULL);
	glCompileShader(vertex);

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &c_FragmentCode, NULL);
	glCompileShader(fragment);

	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);

	glLinkProgram(m_ID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Modular::Shader::Bind()
{
	glUseProgram(m_ID);
}

void Modular::Shader::setInt(const std::string& name, int value)
{
	Bind();
	glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Modular::Shader::setFloat(const std::string& name, float value)
{
	Bind();
	glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value);
}

void Modular::Shader::setVec3(const std::string& name, float x, float y, float z)
{
	Bind();
	glUniform3f(glGetUniformLocation(m_ID, name.c_str()), x, y, z);
}

void Modular::Shader::setVec3(const std::string& name, const glm::vec3& value)
{
	Bind();
	glUniform3fv(glGetUniformLocation(m_ID, name.c_str()), 1, &value[0]);
}

void Modular::Shader::setMat4(const std::string& name, const glm::mat4& mat)
{
	Bind();
	glUniformMatrix4fv(glGetUniformLocation(m_ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}