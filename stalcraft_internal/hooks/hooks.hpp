#ifndef STALCRAFT_HOOKS_HOOKS_HPP
#define STALCRAFT_HOOKS_HOOKS_HPP

#include <Windows.h>
#include <GL/gl.h>

#include <string>
#include <vector>
#include <iostream>

#include <singleton/singleton.hpp>

#include "../helpers/minhook/minhook.hpp"

/*typedef GLint(APIENTRY* glGetUniformLocation_fn)(GLuint, const char*);
typedef void(APIENTRY* glActiveTexture_fn)(GLenum);
typedef void(APIENTRY* glGetUniformiv_fn)(GLuint program, GLint location, GLint* params);
typedef void(APIENTRY* glGetUniformfv_fn)(GLuint program, GLint location, GLfloat* params);
typedef void(APIENTRY* glUniform3f_fn)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void(APIENTRY* glBlendColor_fn)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

#define GL_CURRENT_PROGRAM	0x8B8D
#define GL_ACTIVE_UNIFORMS	0x8B86
#define GL_TEXTURE0			0x84C0
#define GL_CONSTANT_COLOR	0x8001
#define GL_BLEND_COLOR		0x8005
#define GL_ACTIVE_TEXTURE   0x84E0*/

namespace hooks
{
	void initialize();

	namespace handles
	{
		PROC WINAPI		wgl_get_proc_address(LPCSTR lpszProc);
		VOID WINAPI		gl_draw_elements(GLenum mode, GLsizei count, GLenum type, const void* indices);

		namespace originals
		{
			inline decltype(&wgl_get_proc_address) wgl_get_proc_address = nullptr;
			inline decltype(&gl_draw_elements) gl_draw_elements = nullptr;
		}
	}
}

#endif