#pragma once

#include "../Engine/scene_manager.h"
#include "main_scene.h"

namespace engine
{
	void loadScenes()
	{
		SceneManager::addScene(static_cast<Scene*>(new MainScene()));

		SceneManager::changeScene(L"MainScene");
	}
}
