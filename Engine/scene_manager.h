#pragma once

#include "header.h"

namespace engine
{
	class Scene;

	class SceneManager final
	{
	public:
		SceneManager();
		~SceneManager();

		static void initialize();
		static void update();
		static void lateUpdate();
		static void render(HDC const& hDC);

		static void addScene(Scene* scene);
		static void removeScene(std::wstring const& name);
		static void changeScene(std::wstring const& name);

	private:
		static std::unordered_map<std::wstring, Scene*> scenes;
		static Scene* current_scene;
	};
}
