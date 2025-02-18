PROC WINAPI hooks::handles::wgl_get_proc_address(LPCSTR lpszProc)
{
    PROC proc_addreess = handles::originals::wgl_get_proc_address(lpszProc);

    if (strcmp(lpszProc, "glDrawElements") == 0)
    {
        static bool once = false;
        if (proc_addreess)
        {
            if (!once)
            {
                once = true;

                minhook::get().create_hook(proc_addreess, &handles::gl_draw_elements, &handles::originals::gl_draw_elements);
                minhook::get().enable_hook(proc_addreess);
            }
        }
    }

    return proc_addreess;
}