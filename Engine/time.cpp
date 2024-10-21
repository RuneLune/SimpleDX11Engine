#include "time.h"

namespace engine {
	LARGE_INTEGER Time::frequency_;
	LARGE_INTEGER Time::previous_count_;
	LARGE_INTEGER Time::current_count_;

	float Time::delta_time_ = 0.f;

	void Time::initialize()
	{
		QueryPerformanceFrequency(&frequency_);
		QueryPerformanceCounter(&previous_count_);
	}

	void Time::update()
	{
		QueryPerformanceCounter(&current_count_);
		delta_time_ = static_cast<float>(current_count_.QuadPart - previous_count_.QuadPart) / frequency_.QuadPart;
		previous_count_ = current_count_;
	}

	void Time::render(HDC const& hDC)
	{
		int fps = static_cast<int>(1.f / delta_time_);
		static char buffer[256];
		sprintf_s(buffer, "FPS: %d", fps);
		TextOutA(hDC, 0, 0, buffer, static_cast<int>(strlen(buffer)));
	}
}
