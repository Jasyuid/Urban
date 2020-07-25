#include "Application.h"

#include "Cobalt/Events/ApplicationEvent.h"
#include "Cobalt/Log.h"

namespace Cobalt {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		CB_TRACE(e);

		while (true);
	}

}
