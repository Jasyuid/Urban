#pragma once

#include "Cobalt/Core/Input.h"

namespace Cobalt {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedInt(int keycode) override;

		virtual bool IsMouseButtonPressedInt(int button) override;
		virtual std::pair<float, float> GetMousePositionInt() override;
		virtual float GetMouseXInt() override;
		virtual float GetMouseYInt() override;
	};

}
