#ifndef STALCRAFT_HELPERS_MINHOOK_HPP
#define STALCRAFT_HELPERS_MINHOOK_HPP

#include <format>
#include <exception>
#include <stdexcept>

#include <singleton/singleton.hpp>

#include "minhook/minhook.h"

class minhook : public singleton<minhook>
{
	friend class singleton<minhook>;

public:
	minhook();

public:
	void create_hook(void* target, void* detour, void* original);
	void enable_hook(void* hook = MH_ALL_HOOKS);
	void disable_all_hooks();
};

#endif