#pragma once
#include "cbpch.h"

#include "Cobalt/Core.h"
#include "Cobalt/Events/Event.h"

namespace Cobalt {

	// Struct for holding Window data
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		// Default window configuration
		WindowProps(const std::string& title = "Cobalt Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}

	};

	class COBALT_API Window
	{
	public:
		// Function that will handle event callbacks
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

}
