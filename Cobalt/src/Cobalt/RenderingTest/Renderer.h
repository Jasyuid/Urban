#pragma once

#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"


#define GLCall(x) GLClearError();\
	x;\
	CB_CORE_ASSERT(GLLogCall(), #x);

void GLClearError();
bool GLLogCall();

class Renderer
{
public:
	void Draw(VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};