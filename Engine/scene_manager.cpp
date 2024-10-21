#include "scene_manager.h"
#include "scene.h"

namespace engine {
	std::unordered_map<std::wstring, Scene*> SceneManager::scenes = {};
	Scene* SceneManager::current_scene = nullptr;

	SceneManager::SceneManager()
	{
	}

	SceneManager::~SceneManager()
	{
		for (auto const& scene : scenes)
			delete scene.second;
		scenes.clear();
	}

	void SceneManager::initialize()
	{
		current_scene = nullptr;
		for (auto const& scene : scenes)
			scene.second->initialize();
	}

	void SceneManager::update()
	{
		if (current_scene)
			current_scene->update();
	}

	void SceneManager::lateUpdate()
	{
		if (current_scene)
			current_scene->lateUpdate();
	}

	void SceneManager::render(HDC const& hDC)
	{
		if (current_scene)
			current_scene->render(hDC);
	}

	void SceneManager::addScene(Scene* scene)
	{
		scenes[scene->getName()] = scene;
	}

	void SceneManager::removeScene(std::wstring const& name)
	{
		auto scene = scenes.find(name);
		if (scene != scenes.end())
		{
			delete scene->second;
			scenes.erase(scene);
		}
	}

	void SceneManager::changeScene(std::wstring const& name)
	{
		auto scene = scenes.find(name);
		if (scene != scenes.end())
			current_scene = scene->second;
	}
}
