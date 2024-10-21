#pragma once

#include "../Engine/script.h"

namespace engine
{
	class PlayerScript final : public Script
	{
	public:
		PlayerScript() = default;
		~PlayerScript() = default;

		void initialize() final override;
		void update() final override;
		void lateUpdate() final override;
		void render(HDC const& hdc) const final override;

	private:
		HBRUSH brush_{ CreateSolidBrush(RGB(0, 0, 255)) };
		HPEN pen_{ CreatePen(PS_SOLID, 1, RGB(0, 0, 0)) };
		std::pair<float, float> position_{ 50.f, 50.f };
		float speed_{ 255.f };
	};
}
