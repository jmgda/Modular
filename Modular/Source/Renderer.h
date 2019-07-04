#pragma once

#include "Mesh.h"

namespace Modular
{
	class Renderer
	{

	public:

		void Draw(Mesh* mesh);

		void Clear(float red, float green, float blue);

		void SetViewportSize(float width, float height);

		Mesh* CreateCube(Shader* shader, const glm::vec3& lightPos);

	};
}