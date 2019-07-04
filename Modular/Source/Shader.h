#pragma once

#include <glm/glm.hpp>
#include <string>

namespace Modular
{
	class Shader
	{

	public:

		Shader(const std::string& vertexPath, const std::string& fragmentPath);

		void Bind();

		void setInt(const std::string& name, int value);
		void setFloat(const std::string& name, float value);

		void setVec3(const std::string& name, float x, float y, float z);
		void setVec3(const std::string& name, const glm::vec3& value);

		void setMat4(const std::string& name, const glm::mat4& mat);

	private:

		unsigned int m_ID;

	};
}