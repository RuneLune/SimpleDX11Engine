#include "player_script.h"
#include "../Engine/game_object.h"
#include "../Engine/transform.h"
#include "../Engine/input.h"
#include "../Engine/time.h"

namespace engine
{
	void PlayerScript::initialize()
	{
	}

	void PlayerScript::update()
	{
		auto const& transform = getObject()->getComponent<Transform>();
		if (transform)
		{
			auto& [x, y] = position_;

			if (Input::getKey(VK_UP))
			{
				y -= speed_ * Time::getDeltaTime();
			}
			if (Input::getKey(VK_DOWN))
			{
				y += speed_ * Time::getDeltaTime();
			}
			if (Input::getKey(VK_LEFT))
			{
				x -= speed_ * Time::getDeltaTime();
			}
			if (Input::getKey(VK_RIGHT))
			{
				x += speed_ * Time::getDeltaTime();
			}

			transform->setPosition({ static_cast<int>(x), static_cast<int>(y) });
		}
	}

	void PlayerScript::lateUpdate()
	{
	}

	void PlayerScript::render(HDC const& hdc) const
	{
		auto const& transform = getObject()->getComponent<Transform>();
		if (transform)
		{
			auto const& [x, y] = transform->getPosition();

			auto const oldBrush = SelectObject(hdc, brush_);
			auto const oldPen = SelectObject(hdc, pen_);

			Rectangle(hdc, x - 25, y - 25, x + 25, y + 25);

			SelectObject(hdc, oldBrush);
			SelectObject(hdc, oldPen);
		}
	}
}
