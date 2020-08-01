#pragma once

#include "Core.h"
#include "Window.h"
#include "Cobalt/Core/LayerStack.h"
#include "Cobalt/Events/Event.h"
#include "Cobalt/Events/ApplicationEvent.h"
#include "Input.h"

#include "Cobalt/RenderingTest/RenderingTest.h"

namespace Cobalt {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;

		std::unique_ptr<RenderingTest> m_RenderingTest;
	};


	// To be defined in client
	Application* CreateApplication();

}

