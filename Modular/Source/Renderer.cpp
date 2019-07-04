#include "Renderer.h"
#include <glad/glad.h>

void Modular::Renderer::Clear(float red, float green, float blue)
{
	glClearColor(red, green, blue, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
}

void Modular::Renderer::Draw(Mesh* mesh)
{
	mesh->Bind();
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Modular::Renderer::SetViewportSize(float width, float height)
{
	glViewport(0, 0, width, height);
}

Modular::Mesh* Modular::Renderer::CreateCube(Shader* shader, const glm::vec3& lightPos)
{
	Modular::Vertex vertex0;
	vertex0.Position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex0.Normals = glm::vec3(0.0f, 0.0f, 1.0f);

	Modular::Vertex vertex1;
	vertex1.Position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex1.Normals = glm::vec3(0.0f, 0.0f, 1.0f);

	Modular::Vertex vertex2;
	vertex2.Position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex2.Normals = glm::vec3(0.0f, 0.0f, 1.0f);

	Modular::Vertex vertex3;
	vertex3.Position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex3.Normals = glm::vec3(0.0f, 0.0f, 1.0f);


	Modular::Vertex vertex4;
	vertex4.Position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex4.Normals = glm::vec3(1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex5;
	vertex5.Position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex5.Normals = glm::vec3(1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex6;
	vertex6.Position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex6.Normals = glm::vec3(1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex7;
	vertex7.Position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex7.Normals = glm::vec3(1.0f, 0.0f, 0.0f);


	Modular::Vertex vertex8;
	vertex8.Position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex8.Normals = glm::vec3(0.0f, 0.0f, -1.0f);

	Modular::Vertex vertex9;
	vertex9.Position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex9.Normals = glm::vec3(0.0f, 0.0f, -1.0f);

	Modular::Vertex vertex10;
	vertex10.Position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex10.Normals = glm::vec3(0.0f, 0.0f, -1.0f);

	Modular::Vertex vertex11;
	vertex11.Position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex11.Normals = glm::vec3(0.0f, 0.0f, -1.0f);


	Modular::Vertex vertex12;
	vertex12.Position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex12.Normals = glm::vec3(-1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex13;
	vertex13.Position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex13.Normals = glm::vec3(-1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex14;
	vertex14.Position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex14.Normals = glm::vec3(-1.0f, 0.0f, 0.0f);

	Modular::Vertex vertex15;
	vertex15.Position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex15.Normals = glm::vec3(-1.0f, 0.0f, 0.0f);


	Modular::Vertex vertex16;
	vertex16.Position = glm::vec3(-0.5f, 0.5f, 0.5f);
	vertex16.Normals = glm::vec3(0.0f, 1.0f, 0.0f);

	Modular::Vertex vertex17;
	vertex17.Position = glm::vec3(-0.5f, 0.5f, -0.5f);
	vertex17.Normals = glm::vec3(0.0f, 1.0f, 0.0f);

	Modular::Vertex vertex18;
	vertex18.Position = glm::vec3(0.5f, 0.5f, -0.5f);
	vertex18.Normals = glm::vec3(0.0f, 1.0f, 0.0f);

	Modular::Vertex vertex19;
	vertex19.Position = glm::vec3(0.5f, 0.5f, 0.5f);
	vertex19.Normals = glm::vec3(0.0f, 1.0f, 0.0f);


	Modular::Vertex vertex20;
	vertex20.Position = glm::vec3(-0.5f, -0.5f, 0.5f);
	vertex20.Normals = glm::vec3(0.0f, -1.0f, 0.0f);

	Modular::Vertex vertex21;
	vertex21.Position = glm::vec3(-0.5f, -0.5f, -0.5f);
	vertex21.Normals = glm::vec3(0.0f, -1.0f, 0.0f);

	Modular::Vertex vertex22;
	vertex22.Position = glm::vec3(0.5f, -0.5f, -0.5f);
	vertex22.Normals = glm::vec3(0.0f, -1.0f, 0.0f);

	Modular::Vertex vertex23;
	vertex23.Position = glm::vec3(0.5f, -0.5f, 0.5f);
	vertex23.Normals = glm::vec3(0.0f, -1.0f, 0.0f);


	Mesh* mesh = new Mesh(shader, lightPos);

	mesh->MoveTo(glm::vec3(4.0f));

	mesh->AddVertex(vertex0);
	mesh->AddVertex(vertex1);
	mesh->AddVertex(vertex2);

	mesh->AddVertex(vertex2);
	mesh->AddVertex(vertex3);
	mesh->AddVertex(vertex0);


	mesh->AddVertex(vertex4);
	mesh->AddVertex(vertex5);
	mesh->AddVertex(vertex6);

	mesh->AddVertex(vertex6);
	mesh->AddVertex(vertex7);
	mesh->AddVertex(vertex4);


	mesh->AddVertex(vertex8);
	mesh->AddVertex(vertex9);
	mesh->AddVertex(vertex10);

	mesh->AddVertex(vertex10);
	mesh->AddVertex(vertex11);
	mesh->AddVertex(vertex8);


	mesh->AddVertex(vertex12);
	mesh->AddVertex(vertex13);
	mesh->AddVertex(vertex14);

	mesh->AddVertex(vertex14);
	mesh->AddVertex(vertex15);
	mesh->AddVertex(vertex12);


	mesh->AddVertex(vertex16);
	mesh->AddVertex(vertex17);
	mesh->AddVertex(vertex18);

	mesh->AddVertex(vertex18);
	mesh->AddVertex(vertex19);
	mesh->AddVertex(vertex16);


	mesh->AddVertex(vertex20);
	mesh->AddVertex(vertex21);
	mesh->AddVertex(vertex22);

	mesh->AddVertex(vertex22);
	mesh->AddVertex(vertex23);
	mesh->AddVertex(vertex20);

	
	return mesh;
}