#pragma once

#include "Core.h"
#include "cbpch.h"

namespace Cobalt {

	class COBALT_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedInt(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedInt(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionInt(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXInt(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYInt(); }
	
	protected:
		virtual bool IsKeyPressedInt(int keycode) = 0;

		virtual bool IsMouseButtonPressedInt(int button) = 0;
		virtual std::pair<float, float> GetMousePositionInt() = 0;
		virtual float GetMouseXInt() = 0;
		virtual float GetMouseYInt() = 0;

	private:
		static Input* s_Instance;
	};

}