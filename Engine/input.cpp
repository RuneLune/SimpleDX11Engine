#include "input.h"

namespace engine
{
	std::array<KEY_STATE, 256> Input::key_states_ = { KEY_STATE::IDLE };

	void Input::initialize()
	{
		for (auto& key_state : key_states_)
			key_state = KEY_STATE::IDLE;
	}

	void Input::update()
	{
		for (size_t keycode = 0; keycode < Input::key_states_.size(); ++keycode)
		{
			auto& key_state = Input::key_states_[keycode];

			if (GetAsyncKeyState(static_cast<int>(keycode)) & 0x8000)
			{
				if (key_state == KEY_STATE::IDLE || key_state == KEY_STATE::UP)
					key_state = KEY_STATE::DOWN;
				else
					key_state = KEY_STATE::PRESSED;
			}
			else
			{
				if (key_state == KEY_STATE::DOWN || key_state == KEY_STATE::PRESSED)
					key_state = KEY_STATE::UP;
				else
					key_state = KEY_STATE::IDLE;
			}
		}
	}
}
