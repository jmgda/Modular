#include "Mesh.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb_image/stb_image.h>

Modular::Mesh::Mesh(Shader* shader, const glm::vec3& lightPos)
	: m_Shader(shader), m_VertexArray(new unsigned int()), 
	  m_VertexBuffer(new unsigned int()), m_Model(glm::mat4(1.0f)), 
	  m_Position(glm::vec3(0.0f)), m_Scale(glm::vec3(1.0f))
{
	m_Shader->Bind();

	m_Shader->setMat4("model", m_Model);

	m_Shader->setVec3("objectColor", 0.0f, 0.5f, 0.31f);
	m_Shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);
	m_Shader->setVec3("lightPos", lightPos);
}

void Modular::Mesh::Bind()
{
	glBindVertexArray(*m_VertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, *m_VertexBuffer);

	m_Shader->Bind();
}

void Modular::Mesh::AddVertex(Vertex vertex)
{
	m_Vertices.push_back(vertex.Position.x);
	m_Vertices.push_back(vertex.Position.y);
	m_Vertices.push_back(vertex.Position.z);

	m_Vertices.push_back(vertex.Normals.x);
	m_Vertices.push_back(vertex.Normals.y);
	m_Vertices.push_back(vertex.Normals.z);

	glDeleteVertexArrays(1, m_VertexArray);
	glGenVertexArrays(1, m_VertexArray);
	glBindVertexArray(*m_VertexArray);

	glDeleteBuffers(1, m_VertexBuffer);
	glGenBuffers(1, m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, *m_VertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(float), 
		&m_Vertices.front(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
		6 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 
		6 * sizeof(float), (void*)(3 * sizeof(float)));

	glEnableVertexAttribArray(1);
}

void Modular::Mesh::MoveTo(glm::vec3& position)
{
	m_Position = position;

	m_Model = glm::translate(glm::mat4(1.0f), m_Position);
	m_Model = glm::scale(m_Model, m_Scale);

	m_Shader->setMat4("model", m_Model);
}

void Modular::Mesh::Scale(glm::vec3& scale)
{
	m_Scale = scale;

	m_Model = glm::translate(glm::mat4(1.0f), m_Position);
	m_Model = glm::scale(m_Model, m_Scale);

	m_Shader->setMat4("model", m_Model);
}

void Modular::Mesh::ChangeColor(const glm::vec3& color)
{
	m_Shader->setVec3("objectColor", 
		glm::vec3(color.x / 255.0f, color.y / 255.0f, color.z / 255.0f));
}