#pragma once

#include <Windows.h>
#include <array>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <mmsystem.h>
#include <dinput.h>
#include <gdiplus.h>

#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdiplus.lib")

#define X first
#define Y second

using Position = std::pair<int, int>;

inline Position operator+(Position const& lhs, Position const& rhs)
{
	return { lhs.X + rhs.X, lhs.Y + rhs.Y };
}

inline Position operator-(Position const& lhs, Position const& rhs)
{
	return { lhs.X - rhs.X, lhs.Y - rhs.Y };
}

inline Position operator*(Position const& lhs, int rhs)
{
	return { lhs.X * rhs, lhs.Y * rhs };
}

inline Position operator/(Position const& lhs, int rhs)
{
	return { lhs.X / rhs, lhs.Y / rhs };
}
