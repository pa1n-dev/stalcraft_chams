typedef GLint(APIENTRY* glGetUniformLocation_fn)(GLuint, const char*);
typedef void(APIENTRY* glGetUniformiv_fn)(GLuint program, GLint location, GLint* params);
typedef void(APIENTRY* glActiveTexture_fn)(GLenum);
typedef void(APIENTRY* glGetUniformfv_fn)(GLuint program, GLint location, GLfloat* params);
typedef void(APIENTRY* glUniform3f_fn)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void(APIENTRY* glBlendColor_fn)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

#define GL_CURRENT_PROGRAM  0x8B8D
#define GL_ACTIVE_UNIFORMS  0x8B86
#define GL_TEXTURE0         0x84C0
#define GL_CONSTANT_COLOR   0x8001
#define GL_BLEND_COLOR      0x8005

VOID WINAPI hooks::handles::gl_draw_elements(GLenum mode, GLsizei count, GLenum type, const void* indices)
{
    static glGetUniformLocation_fn  glGetUniformLocation    = (glGetUniformLocation_fn)wglGetProcAddress("glGetUniformLocation");
    static glGetUniformiv_fn        glGetUniformiv          = (glGetUniformiv_fn)wglGetProcAddress("glGetUniformiv");
    static glActiveTexture_fn       glActiveTexture         = (glActiveTexture_fn)wglGetProcAddress("glActiveTexture");
    static glGetUniformfv_fn        glGetUniformfv          = (glGetUniformfv_fn)wglGetProcAddress("glGetUniformfv");
    static glUniform3f_fn           glUniform3f             = (glUniform3f_fn)wglGetProcAddress("glUniform3f");
    static glBlendColor_fn          glBlendColor            = (glBlendColor_fn)wglGetProcAddress("glBlendColor");

    GLint current_program;
    glGetIntegerv(GL_CURRENT_PROGRAM, &current_program);

    GLint is_animated_location = glGetUniformLocation(current_program, "isAnimated");
    GLint emission_color_location = glGetUniformLocation(current_program, "emissionColor");
    GLint diffuse_color_location = glGetUniformLocation(current_program, "diffuseColor");
    GLint specular_color_location = glGetUniformLocation(current_program, "specularColor");
    GLint light_sun_color_location = glGetUniformLocation(current_program, "g_LightSunColor");

    bool is_player = false;

    if (is_animated_location != -1 && emission_color_location != -1 && diffuse_color_location != -1 && specular_color_location != -1 && light_sun_color_location != -1)
    {
        if (
            count != 24// стекло €щика
            && count != 48// Ѕ”–я“ Ё –јЌ
            && count != 60// дверь
            && count != 102// ветка дерева
            && count != 108// часть генератора
            && count != 141// радиоактивна€ лужа
            && count != 216// стол
            && count != 222// петли от двери
            && count != 321// лужица какужица
            && count != 384// маленький мох
            && count != 570// дверь
            && count != 576// средн€€ паутина
            && count != 594// двери
            && count != 840// свечки
            && count != 864// €щик дерев€нный
            && count != 972// часть генератора
            && count != 1230// сейф
            && count != 1419// дверь
            && count != 1434// газова€ плита
            && count != 1740// 2 часть свечки
            && count != 1842// хз очень далеко
            && count != 1866// дверь
            && count != 2160// дверь
            && count != 2628// дверь гаража
            && count != 2721// вентил€ци€
            && count != 3672// дверь гаража
            && count != 4320// бочки
            && count != 4902// елочка
            && count != 5148// Ѕ”–я“
            && count != 5274// новогодний кейс
            && count != 6756// газова€ плита
            && count != 7530// дверь
            && count != 7548// стол
            && count != 9033// генератор 1
            && count != 9057// генератор 2
            && count != 9648// генератор 3
            && count != 233670// елочка иголки
            && count != 16344//двери на колесиках
            && count != 3318//хуйн€ от двери
            && count != 1917//двойна€ дверь
            && count != 4284//двойна€ дверь
            && count != 1662//дверь
            && count != 4098//дверь
            && count != 1827//двойна€ дверь
            && count != 828//дверь
            && count != 960//дверь
            && count != 6366//дверь больша€
            && count != 414//дверь
            && count != 912//дверь
            && count != 939//дверь
            && count != 510//дверь
            && count != 396//дверь
            && count != 543//дверь
            && count != 3792//окна нахуй
            && count != 1887//окна нахуй
            && count != 330//окна нахуй
            && count != 465//окна нахуй
            && count != 1887//окна нахуй
            && count != 2193//двери
            && count != 1596//двери
            && count != 297//двери
            && count != 459//двери
            && count != 1095//двери
            && count != 1026//двери
            && count != 366//двери
            && count != 1242//двери
            && count != 2052//двери
            && count != 948//двери
            && count != 846//двери
            && count != 852//двери
            && count != 1464//двери
            && count != 1386//двери
            && count != 228//двери
            && count != 1692//двери
            && count != 1758//двери
            && count != 444//двери
            && count != 480//двери     
            && count != 894//двери
            && count != 1698//двери
            && count != 3408//двери
            && count != 426//двери
            && count != 432//двери
            && count != 327//двери
            && count != 420//двери
            && count != 429//двери
            && count != 861//двери
            && count != 711//двери
            && count != 645//двери
            && count != 897//двери
            && count != 2070//двери
            && count != 930//двери
            && count != 345//двери
            && count != 4158//двери
            && count != 7170//двери
            && count != 447//двери
            && count != 891//двери
            && count != 1788//двери
            && count != 735//двери
            && count != 582//двери
            && count != 597//двери
            && count != 1224//двери
            && count != 1302//двери
            && count != 672//“»ѕќ Ѕ”–я“ Ќќ ƒЋя Ћќ’ќ¬
            && count != 7032//“»ѕќ Ѕ”–я“ Ќќ ƒЋя Ћќ’ќ¬
            )
        {
            is_player = true;
        }
    }


    if (is_player)
    {
        GLfloat backup_emission_color[3];
        GLfloat backup_diffuse_color[3];
        GLfloat backup_specular_color[3];
        GLfloat backup_light_sun_color[3];

        GLfloat backup_depth_range[2];
        GLint backup_depth_func;

        GLint backup_texture;

        GLint num_textures = 99;
        std::vector<GLint> saved_samplers(num_textures);
        std::vector<GLuint> saved_textures(num_textures);

        GLfloat backup_blend_color[4];
        GLint backup_blend_src, backup_blend_dst;

        //SAVE BACKUP
        {
            glGetFloatv(GL_BLEND_COLOR, backup_blend_color);

            glGetIntegerv(GL_BLEND_SRC, &backup_blend_src);
            glGetIntegerv(GL_BLEND_DST, &backup_blend_dst);

            glGetUniformfv(current_program, emission_color_location, backup_emission_color);
            glGetUniformfv(current_program, diffuse_color_location, backup_diffuse_color);
            glGetUniformfv(current_program, specular_color_location, backup_specular_color);
            glGetUniformfv(current_program, light_sun_color_location, backup_light_sun_color);

            glGetFloatv(GL_DEPTH_RANGE, backup_depth_range);
            glGetIntegerv(GL_DEPTH_FUNC, &backup_depth_func);

            glGetIntegerv(GL_TEXTURE_BINDING_2D, &backup_texture);
        }

        {
            static GLuint texture = 0;
            if (!texture)
                glGenTextures(1, &texture);

            glEnable(GL_BLEND);
            glBlendFunc(GL_ONE, GL_CONSTANT_COLOR);
            glBlendColor(1.0f, 0.0f, 0.0f, 1.0f);

            glUniform3f(emission_color_location, 1.0f, 0.0f, 0.0f);
            glUniform3f(diffuse_color_location, 1.0f, 0.0f, 0.0f);
            glUniform3f(specular_color_location, 1.0f, 0.0f, 0.0f);
            glUniform3f(light_sun_color_location, 1.0f, 0.0f, 0.0f);

            unsigned char color[4] = { 255,  0,  0,  255 };

            glDepthRange(0.0, 0.0);

            for (GLint i = 0; i < num_textures; ++i)
            {
                GLint location = glGetUniformLocation(current_program, ("usedTextures[" + std::to_string(i) + "]").c_str());
                if (location == -1)
                    continue;

                GLint sampler;
                glGetUniformiv(current_program, location, &sampler);
                glActiveTexture(GL_TEXTURE0 + sampler);

                GLint bound_texture;
                glGetIntegerv(GL_TEXTURE_BINDING_2D, &bound_texture);
                saved_samplers[i] = sampler;
                saved_textures[i] = bound_texture;

                glBindTexture(GL_TEXTURE_2D, texture);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
            }
        }

        handles::originals::gl_draw_elements(mode, count, type, indices);

        glUniform3f(emission_color_location, backup_emission_color[0], backup_emission_color[1], backup_emission_color[2]);
        glUniform3f(diffuse_color_location, backup_diffuse_color[0], backup_diffuse_color[1], backup_diffuse_color[2]);
        glUniform3f(specular_color_location, backup_specular_color[0], backup_specular_color[1], backup_specular_color[2]);
        glUniform3f(light_sun_color_location, backup_light_sun_color[0], backup_light_sun_color[1], backup_light_sun_color[2]);

        glDepthRange(backup_depth_range[0], backup_depth_range[1]);
        glDepthFunc(backup_depth_func);

        glEnable(GL_BLEND);
        glBlendColor(backup_blend_color[0], backup_blend_color[1], backup_blend_color[2], backup_blend_color[3]);
        glBlendFunc(backup_blend_src, backup_blend_dst);

        for (GLint i = 0; i < num_textures; ++i)
        {
            GLint sampler = saved_samplers[i];
            GLuint texture = saved_textures[i];

            if (sampler != -1)
            {
                glActiveTexture(GL_TEXTURE0 + sampler);
                glBindTexture(GL_TEXTURE_2D, texture);
            }
        }

        return;
    }
    
    handles::originals::gl_draw_elements(mode, count, type, indices);
}