#pragma once

#include "header.h"


namespace engine
{
	enum class KEY_STATE { IDLE, DOWN, PRESSED, UP };

	class Input
	{
	public:
		static void initialize();
		static void update();

		inline static KEY_STATE const& getKeyState(int const& keycode) { return key_states_[keycode]; }
		inline static bool getKeyDown(int const& keycode) { return key_states_[keycode] == KEY_STATE::DOWN; }
		inline static bool getKeyUp(int const& keycode) { return key_states_[keycode] == KEY_STATE::UP; }
		inline static bool getKey(int const& keycode) { return key_states_[keycode] == KEY_STATE::PRESSED; }

	private:
		static std::array<KEY_STATE, 256> key_states_;
	};
}
