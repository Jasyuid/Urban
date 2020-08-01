#include "cbpch.h"
#include "Renderer.h"

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall()
{
	while (GLenum error = glGetError())
	{
		CB_CORE_ERROR("OpenGL Error ({0})", error);
		return false;
	}
	return true;
}

void Renderer::Draw(VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}