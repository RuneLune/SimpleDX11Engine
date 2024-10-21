#pragma once

#include "entity.h"
#include "header.h"

namespace engine
{
	class Component;
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void initialize() const final;
		virtual void update() const final;
		virtual void lateUpdate() const final;
		virtual void render(HDC const&) const final;

		void addComponent(Component* const& component);
		template<class T> T* getComponent() const
		{
			for (auto const& component : components_)
				if (auto const t = dynamic_cast<T*>(component))
					return t;

			return nullptr;
		}
	private:
		std::vector<Component*> components_;
	};
}
