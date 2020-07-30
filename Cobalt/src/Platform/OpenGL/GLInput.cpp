#include "cbpch.h" 
#include "Cobalt/Core/Input.h"

#include "Cobalt/Core/Application.h"

#include <GLFW/glfw3.h>

// Input definitions when using GLFW (OpenGL)
#ifdef CB_OPENGL

namespace Cobalt {

	bool Input::IsKeyPressed(unsigned int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool Input::IsMouseButtonPressed(unsigned int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> Input::GetMousePosition()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
	}

	float Input::GetMouseX()
	{
		auto pos = GetMousePosition();
		return pos.first;
	}

	float Input::GetMouseY()
	{
		auto pos = GetMousePosition();
		return pos.second;
	}

}

#endif