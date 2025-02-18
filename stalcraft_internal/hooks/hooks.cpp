#include "hooks.hpp"

#include "handles/gl_draw_elements.h"
#include "handles/wgl_get_proc_address.h"

void hooks::initialize()
{
    minhook::get().create_hook(wglGetProcAddress, &handles::wgl_get_proc_address, &handles::originals::wgl_get_proc_address);
    minhook::get().enable_hook();
}