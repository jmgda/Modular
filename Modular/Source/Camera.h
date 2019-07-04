#pragma once

#include "Shader.h"
#include "Mesh.h"
#include <glm/glm.hpp>
#include <vector>

namespace Modular
{
	enum Direction
	{
		Right, Left, Up, Down, Forwards, Backwards
	};

	enum Rotation { Yaw, Pitch, Roll };

	enum Size { Width, Height, Lenght };

	class Camera
	{

	public:

		Camera(std::vector<Mesh*>* meshes, float fov, float aspectRatio);

		void Move(Direction direction, float distance);
		void Rotate(Rotation rotation, float offset);

		void AdjustAspectRatio(float newAspectRatio);

		void UpdateMeshes(std::vector<Mesh*>* newMeshes);

	private:

		std::vector<Mesh*>* m_Meshes;

		float m_Fov, m_Yaw, m_Pitch, m_AspectRatio;

		glm::vec3 m_Position, m_Front, m_Up;

		void UpdatePosition();

		void SetShadersUniform(const std::string& name, const glm::mat4& mat);

	};
}