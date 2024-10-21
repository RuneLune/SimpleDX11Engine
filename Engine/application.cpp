#include "application.h"

#include "game_object.h"
#include "input.h"
#include "time.h"
#include "scene_manager.h"

namespace engine {
	Application::Application() : hWnd_(nullptr), hDC_(nullptr), back_buffer_(nullptr), back_buffer_dc_(nullptr) { }

	Application::~Application()
	{
		if (hDC_)
			ReleaseDC(hWnd_, hDC_);
		hWnd_ = nullptr;
		hDC_ = nullptr;
	}

	void Application::initialize(HWND const& hWnd, int const& width, int const& height)
	{
		hWnd_ = hWnd;
		hDC_ = GetDC(hWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		SetWindowPos(hWnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, SWP_NOMOVE);

		back_buffer_ = CreateCompatibleBitmap(hDC_, width, height);
		back_buffer_dc_ = CreateCompatibleDC(hDC_);
		auto const& old_bitmap = static_cast<HBITMAP>(SelectObject(back_buffer_dc_, back_buffer_));
		DeleteObject(old_bitmap);

		Input::initialize();
		Time::initialize();
		SceneManager::initialize();
	}

	void Application::run()
	{
		update();
		lateUpdate();
		render();
	}

	void Application::update()
	{
		Input::update();
		Time::update();
		SceneManager::update();
	}

	void Application::lateUpdate()
	{
		SceneManager::lateUpdate();
	}

	void Application::render() const
	{
		RECT bg_rect;
		GetClientRect(hWnd_, &bg_rect);
		FillRect(back_buffer_dc_, &bg_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		SceneManager::render(back_buffer_dc_);
		Time::render(back_buffer_dc_);

		// print back buffer to window
		BitBlt(hDC_, 0, 0, bg_rect.right, bg_rect.bottom, back_buffer_dc_, 0, 0, SRCCOPY);
	}
}
