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

};
