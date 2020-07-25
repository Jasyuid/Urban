#pragma once

#include "Core.h"
#include "Window.h"
#include "Cobalt/LayerStack.h"
#include "Events/Event.h"
#include "Cobalt/Events/ApplicationEvent.h"


namespace Cobalt {

	class COBALT_API Application
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

	private:
		static Application* s_Instance;
	};


	// To be defined in client
	Application* CreateApplication();

}

