#pragma once

#include "header.h"
#include "entity.h"

namespace engine
{
	class GameObject;

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void initialize() = 0;
		virtual void update() final;
		virtual void lateUpdate() final;
		virtual void render(HDC const&) const final;
		virtual void addObject(GameObject* const&) final;

	private:
		std::vector<GameObject*> objects;
	};
}
