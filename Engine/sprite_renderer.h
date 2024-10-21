#pragma once

#include "header.h"
#include "component.h"

namespace engine
{
	class SpriteRenderer final : public Component
	{
	public:
		SpriteRenderer();
		virtual ~SpriteRenderer();

		void initialize() override final;
		void update() override final;
		void lateUpdate() override final;
		void render(HDC const& hdc) const override final;

		void loadSprite(std::wstring const& path);

	private:
		Gdiplus::Image* sprite_;
		INT width_;
		INT height_;
	};
}
