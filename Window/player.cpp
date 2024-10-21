#include "player.h"

#include "../Engine/transform.h"
#include "player_script.h"

namespace engine
{
	Player::Player() : GameObject()
	{
		setName(L"Player");
		addComponent(static_cast<Component*>(new Transform()));
		getComponent<Transform>()->setObject(this);
		getComponent<Transform>()->setPosition({ 10, 10 });
		addComponent(static_cast<Component*>(new PlayerScript()));
		getComponent<PlayerScript>()->setObject(this);
	}
}
