#pragma once

#include "Cobalt/Layer.h"

namespace Cobalt {

	class COBALT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetatch();
		void OnUpdate();
		void OnEvent(Event& event);

	protected:
		float m_Time = 0.0f;

	};

}
