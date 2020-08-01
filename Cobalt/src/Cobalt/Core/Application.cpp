#include "cbpch.h"
#include "Application.h"

#include "KeyCodes.h"
#include "MouseButtonCodes.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Cobalt {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		CB_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		// OPENGL TESTING
		m_RenderingTest = std::unique_ptr<RenderingTest>(new RenderingTest());
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
				break;
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			// Window backgroud
			glClearColor(0, 0, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			// Update Layers
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
			
			// TESTING INPUT
			if (Input::IsMouseButtonPressed(CB_MOUSE_BUTTON_LEFT))
			{
				CB_TRACE("Left Mouse Button Pressed!");
			}

			// OPENGL TESTING
			m_RenderingTest->OnUpdate();

			m_Window->OnUpdate();

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}
