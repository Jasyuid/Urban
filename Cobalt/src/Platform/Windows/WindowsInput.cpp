#include "cbpch.h" 
#include "WindowsInput.h"

#include "Cobalt/Application.h"

#include <GLFW/glfw3.h>

namespace Cobalt {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedInt(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedInt(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::GetMousePositionInt()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return std::make_pair((float)xpos, (float)ypos);
	}

	float WindowsInput::GetMouseXInt()
	{
		auto pos = GetMousePositionInt();
		return pos.first;
	}

	float WindowsInput::GetMouseYInt()
	{
		auto pos = GetMousePositionInt();
		return pos.second;
	}

}