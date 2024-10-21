#pragma once

#include "header.h"

namespace engine
{
	class Application final
	{
	public:
		Application();
		~Application();

		void initialize(HWND const&, int const&, int const&);
		void run();

		void update();
		void lateUpdate();
		void render() const;

	private:
		HWND hWnd_;
		HDC hDC_;
		HBITMAP back_buffer_;
		HDC back_buffer_dc_;
	};
}
