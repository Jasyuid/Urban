#include "Application.h"

#include "Urban/Events/ApplicationEvent.h"
#include "Urban/Log.h"

namespace Urban {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		UB_TRACE(e);

		while (true);
	}

}
