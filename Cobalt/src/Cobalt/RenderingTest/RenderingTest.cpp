#include "cbpch.h"
#include "RenderingTest.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <fstream>

//#include "VertexBuffer.h"
//#include "VertexBufferLayout.h"
//#include "VertexArray.h"
//#include "IndexBuffer.h"
//#include "Shader.h"

RenderingTest::RenderingTest()
{
	Init();
}

RenderingTest::~RenderingTest()
{
	Shutdown();
}

VertexArray* va;
VertexBuffer* vb;
IndexBuffer* ib;
Shader* shader;

int location;

void RenderingTest::Init()
{
	CB_CORE_INFO("Starting Renderer");

	float positions[] = {
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f,
		-0.5f,  0.5f
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	va = new VertexArray();
	vb = new VertexBuffer(positions, 4 * 2 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	va->AddBuffer(*vb, layout);
	
	ib = new IndexBuffer(indices, 6);

	shader = new Shader("res/shaders/Basic.shader");
	shader->Bind();
	shader->setUniform4f("u_Color", 0.0f, 0.8f, 0.2f, 1.0f);
	
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
}
