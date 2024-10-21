#include "main_scene.h"

#include "player.h"
#include "../Engine/game_object.h"
#include "../Engine/transform.h"

namespace engine
{
	MainScene::MainScene() : Scene()
	{
		setName(L"MainScene");
		initialize();
	}

	MainScene::~MainScene()
	{
		Scene::~Scene();
	}

	void MainScene::initialize()
	{
		GameObject* player = new Player();
		player->getComponent<Transform>()->setPosition({ 10, 10 });
		addObject(player);
	}
}
