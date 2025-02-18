#include "hooks/hooks.hpp"

BOOL APIENTRY DllMain(HMODULE handle_module, DWORD ul_reason_for_call, LPVOID reserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            hooks::initialize();
            break;
        }
    }
    return TRUE;
}