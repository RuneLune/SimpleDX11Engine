#pragma once

#include "component.h"
//#include "game_object.h"

namespace engine
{
	class Script : public Component
	{
	public:
		Script() = default;
		virtual ~Script() = default;

		void initialize() override;
		void update() override;
		void lateUpdate() override;
		void render(HDC const& hdc) const override;

	//protected:
	//	template<class T>
	//	T* getComponent() const
	//	{
	//		return getObject()->getComponent<T>();
	//	}

	private:
	};
}
