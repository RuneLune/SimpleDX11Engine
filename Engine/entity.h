#pragma once

#include "header.h"

namespace engine
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		inline void setName(std::wstring const& name) { name_ = name; }
		inline std::wstring const& getName() const { return name_; }

	private:
		std::wstring name_;
	};
}

