#pragma once

#include "Shader.h"
#include <glm/glm.hpp>
#include <vector>

namespace Modular
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Normals;
	};

	class Mesh
	{

	public:

		Mesh(Shader* shader, const glm::vec3& lightPos);

		void Bind();

		void AddVertex(Vertex vertex);

		void MoveTo(glm::vec3& position);
		void Scale(glm::vec3& scale);

		void ChangeColor(const glm::vec3& color);

		Shader* GetShader() { return m_Shader; }

		void SetModel(glm::mat4 newModel) { m_Model = newModel; }

	private:

		Shader* m_Shader;

		std::vector<float> m_Vertices;

		unsigned int* m_VertexArray;
		unsigned int* m_VertexBuffer;

		glm::mat4 m_Model;
		glm::vec3 m_Position;
		glm::vec3 m_Scale;

	};
}