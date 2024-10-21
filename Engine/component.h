#pragma once

#include "header.h"

namespace engine
{
	class GameObject;
	class Component
	{
	public:
		Component();
		virtual ~Component() = default;

		inline void setObject(GameObject* const& object) { object_ = object; }
		inline GameObject* getObject() const { return object_; }

		virtual void initialize() = 0;
		virtual void update() = 0;
		virtual void lateUpdate() = 0;
		virtual void render(HDC const&) const = 0;

	private:
		GameObject* object_;
	};
}
