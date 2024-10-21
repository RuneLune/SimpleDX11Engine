#include "scene.h"
#include "game_object.h"

namespace engine
{
	Scene::Scene() : Entity()
	{
		objects.reserve(255);
	}

	Scene::~Scene()
	{
		for (auto const& object_ptr : objects)
			delete object_ptr;
		objects.clear();
	}

	void Scene::initialize()
	{
	}

	void Scene::update()
	{
		for (auto const& object_ptr : objects)
			object_ptr->update();
	}

	void Scene::lateUpdate()
	{
		for (auto const& object_ptr : objects)
			object_ptr->lateUpdate();
	}

	void Scene::render(HDC const& hDC) const
	{
		for (auto const& object_ptr : objects)
			object_ptr->render(hDC);
	}

	void Scene::addObject(GameObject* const& object_ptr)
	{
		objects.push_back(object_ptr);
	}
}
