#pragma once

#include "../Engine/scene.h"

namespace engine
{
	class MainScene final : public Scene
	{
	public:
		MainScene();
		~MainScene();

		void initialize() final override;
	};
}
