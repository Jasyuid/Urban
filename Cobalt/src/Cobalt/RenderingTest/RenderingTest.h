#pragma once

#include "Renderer.h"

class RenderingTest
{
public:
	RenderingTest();
	~RenderingTest();

	void OnUpdate();

private:
	void Init();
	void Shutdown();

private:
	Renderer m_Renderer;

	VertexArray* va;
	VertexBuffer* vb;
	IndexBuffer* ib;
	Shader* shader;

	Texture* texture;

};
