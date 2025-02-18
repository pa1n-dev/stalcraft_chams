#include "minhook.hpp"
#include <iostream>

minhook::minhook()
{
	const MH_STATUS status = MH_Initialize();

	if (status != MH_OK)
		throw;
}

void minhook::create_hook(void* target, void* detour, void* original)
{
	const MH_STATUS status = MH_CreateHook(static_cast<LPVOID>(target), static_cast<PVOID>(detour), static_cast<LPVOID*>(original));

	if (status != MH_OK)
		throw;
}

void minhook::enable_hook(void* hook)
{
	const MH_STATUS status = MH_EnableHook(hook);

	if (status != MH_OK)
		throw;
}

void minhook::disable_all_hooks()
{
	const MH_STATUS disable_hook_status = MH_DisableHook(MH_ALL_HOOKS);

	if (disable_hook_status != MH_OK)
		throw;

}