#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Modular::Camera::Camera(std::vector<Mesh*>* meshes, float fov, float aspectRatio)
	: m_Meshes(meshes), m_Fov(fov), m_Yaw(-90.0f), m_Pitch(0.0f), 
	  m_AspectRatio(aspectRatio), m_Position(glm::vec3(0.0f, 0.0f, 3.0f)), 
	  m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), m_Up(glm::vec3(0.0f, 1.0f, 0.0f))
{
	glm::mat4 projection = glm::perspective(
		glm::radians(m_Fov), aspectRatio, 0.1f, 100.0f);

	SetShadersUniform("projection", projection);
	UpdatePosition();
}

void Modular::Camera::Move(Direction direction, float distance)
{
	switch (direction)
	{
		case Direction::Right:
			m_Position += glm::normalize(glm::cross(m_Front, m_Up)) * distance; break;
		case Direction::Left:
			m_Position -= glm::normalize(glm::cross(m_Front, m_Up)) * distance; break;

		case Direction::Up: m_Position += m_Up * distance; break;
		case Direction::Down: m_Position -= m_Up * distance; break;

		case Direction::Forwards: m_Position += m_Front * distance; break;
		case Direction::Backwards: m_Position -= m_Front * distance; break;
	}

	UpdatePosition();
}

void Modular::Camera::Rotate(Rotation rotation, float offset)
{
	offset *= 0.1f;

	if (rotation == Rotation::Yaw) m_Yaw += offset;

	if (rotation == Rotation::Pitch)
	{
		if (m_Pitch > 89.0f) m_Pitch = 89.0f;
		if (m_Pitch < -89.0f) m_Pitch = -89.0f;

		m_Pitch += offset;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_Front = glm::normalize(front);

	UpdatePosition();
}

void Modular::Camera::AdjustAspectRatio(float newAspectRatio)
{
	m_AspectRatio = newAspectRatio;

	glm::mat4 projection = glm::perspective(
		glm::radians(m_Fov), newAspectRatio, 0.1f, 100.0f);

	SetShadersUniform("projection", projection);
}

void Modular::Camera::UpdateMeshes(std::vector<Mesh*>* newMeshes)
{
	m_Meshes = newMeshes;

	glm::mat4 projection = glm::perspective(
		glm::radians(m_Fov), m_AspectRatio, 0.1f, 100.0f);

	SetShadersUniform("projection", projection);

	UpdatePosition();
}

void Modular::Camera::UpdatePosition()
{
	glm::mat4 view = glm::lookAt(m_Position, m_Position + m_Front, m_Up);
	SetShadersUniform("view", view);
}

void Modular::Camera::SetShadersUniform(const std::string& name, const glm::mat4& mat)
{
	for (int i = 0; i < m_Meshes->size(); i++)
	{
		(*m_Meshes)[i]->GetShader()->setMat4(name, mat);
	}
}