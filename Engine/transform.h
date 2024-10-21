#pragma once
#pragma once

#include "header.h"
#include "component.h"

namespace engine
{
	class Transform final : public Component
	{
	public:
		Transform() = default;
		~Transform() = default;

		void initialize() override;
		void update() override;
		void lateUpdate() override;
		void render(HDC const&) const override;

		inline void setPosition(Position const& position) { position_ = position; }
		inline Position const& getPosition() const { return position_; };

	private:
		Position position_;
	};
}
