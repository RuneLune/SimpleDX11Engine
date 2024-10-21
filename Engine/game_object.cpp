#include "game_object.h"

#include "input.h"
#include "time.h"
#include "component.h"

namespace engine
{
	GameObject::GameObject() : Entity(), components_()
	{
	}

	GameObject::~GameObject()
	{
		for (auto const& component : components_)
			delete component;
		components_.clear();
		Entity::~Entity();
	}

	void GameObject::initialize() const
	{
		for (auto const& component : components_)
			component->initialize();
	}

	void GameObject::update() const
	{
		for (auto const& component : components_)
			component->update();
	}

	void GameObject::lateUpdate() const
	{
		for (auto const& component : components_)
			component->lateUpdate();
	}

	void GameObject::render(HDC const& hDC) const
	{
		for (auto const& component : components_)
			component->render(hDC);
	}

	void GameObject::addComponent(Component* const& component) {
		component->setObject(this);
		components_.push_back(component);
	}
}
