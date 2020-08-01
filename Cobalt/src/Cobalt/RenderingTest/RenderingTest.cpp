#include "cbpch.h"
#include "RenderingTest.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <fstream>

RenderingTest::RenderingTest()
{
	Init();
}

RenderingTest::~RenderingTest()
{
	Shutdown();
}

int location;

void RenderingTest::Init()
{
	CB_CORE_INFO("Starting Renderer");

	float positions[] = {
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_BLEND));

	va = new VertexArray();
	vb = new VertexBuffer(positions, 4 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va->AddBuffer(*vb, layout);
	
	ib = new IndexBuffer(indices, 6);

	glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.125f, 1.125f, -1.0f, 1.0f);

	glm::mat4 mvp = proj;

	shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
	shader->setUniform4f("u_Color", 0.0f, 0.8f, 0.2f, 1.0f);
	shader->setUniformMat4f("u_MVP", mvp);
	
	texture = new Texture("res/textures/cyndaquil.png");
	//texture = new Texture("res/textures/abstract.jpg");
	texture->Bind();
	shader->setUniform1i("u_Texture", 0);

	va->Unbind();
	vb->Unbind();
	ib->Unbind();
	shader->Unbind();
}

float b = 0.2f;
float g = 0.8f;
float inc = 0.02f;

void RenderingTest::OnUpdate()
{
	
	shader->Bind();
	shader->setUniform4f("u_Color", 0.0f, g, b, 1.0f);

	m_Renderer.Draw(*va, *ib, *shader);

	if (b > 0.8f)
		inc = -0.01f;
	else if (b < 0.2f)
		inc = 0.01f;

	b += inc;
	g -= inc;
}


void RenderingTest::Shutdown()
{
	CB_CORE_INFO("Shutting Down Renderer");

	delete va;
	delete vb;
	delete ib;
	delete shader;
	delete texture;
}
