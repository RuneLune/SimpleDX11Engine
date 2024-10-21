#include "sprite_renderer.h"
#include "game_object.h"
#include "transform.h"

namespace engine
{
	SpriteRenderer::SpriteRenderer()
		: sprite_(nullptr)
		, width_(0)
		, height_(0)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
		if (sprite_)
		{
			delete sprite_;
			sprite_ = nullptr;
		}
	}
	void SpriteRenderer::initialize()
	{
	}
	void SpriteRenderer::update()
	{
	}
	void SpriteRenderer::lateUpdate()
	{
	}
	void SpriteRenderer::render(HDC const& hdc) const
	{
		if (sprite_)
		{
			auto const& transform = getObject()->getComponent<Transform>();
			if (transform)
			{
				Gdiplus::Graphics graphics(hdc);
				graphics.DrawImage(sprite_, transform->getPosition().X, transform->getPosition().Y, width_, height_);
			}
		}
	}
	void SpriteRenderer::loadSprite(std::wstring const& path)
	{
		if (sprite_)
		{
			delete sprite_;
			sprite_ = nullptr;
		}

		sprite_ = Gdiplus::Image::FromFile(path.c_str());
		width_ = sprite_->GetWidth();
		height_ = sprite_->GetHeight();
	}
}
