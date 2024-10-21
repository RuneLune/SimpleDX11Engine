#pragma once

#include "header.h"

namespace engine {
	class Time
	{
	public:
		static void initialize();
		static void update();
		static void render(HDC const&);

		inline static float const& getDeltaTime() { return delta_time_; }

	private:
		static LARGE_INTEGER frequency_;
		static LARGE_INTEGER previous_count_;
		static LARGE_INTEGER current_count_;

		static float delta_time_;
	};
}
