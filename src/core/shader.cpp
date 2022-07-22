#include "shader.h"
#include <filesystem>
#include <fstream>
#include "spdlog/spdlog.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Shader::Shader(const std::string &shader_dir, const std::string &shader_file_name)
{
    // we assume that all shader files are in app/{app_name}/shaders - folder
    // and also vertex and fragment shader file names are identical

    const auto shader_vert_path = shader_dir + shader_file_name + ".vs";
    const auto shader_frag_path = shader_dir + shader_file_name + ".fs";

    if (!std::filesystem::exists(shader_vert_path))
    {
        spdlog::error("Invalid vertex shader path: {0}", shader_vert_path);
        return;
    }

    if (!std::filesystem::exists(shader_frag_path))
    {
        spdlog::error("Invalid fragment shader path: {0}", shader_frag_path);
        return;
    }

    std::ifstream ifs_vert{shader_vert_path};
    std::string shader_vert_code((std::istreambuf_iterator<char>(ifs_vert)),
                                 (std::istreambuf_iterator<char>()));

    std::ifstream ifs_frag{shader_frag_path};
    std::string shader_frag_code((std::istreambuf_iterator<char>(ifs_frag)),
                                 (std::istreambuf_iterator<char>()));

    const char *shader_vert_content = shader_vert_code.c_str();
    const char *shader_frag_content = shader_frag_code.c_str();

    unsigned int shader_vert;
    shader_vert = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader_vert, 1, &shader_vert_content, nullptr);
    glCompileShader(shader_vert);
    compile(shader_vert, ShaderCompileTarget::SHADER);

    unsigned int shader_frag;
    shader_frag = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader_frag, 1, &shader_frag_content, nullptr);
    glCompileShader(shader_frag);
    compile(shader_frag, ShaderCompileTarget::SHADER);

    id = glCreateProgram();
    glAttachShader(id, shader_vert);
    glAttachShader(id, shader_frag);
    glLinkProgram(id);
    compile(id, ShaderCompileTarget::PROGRAM);

    glDeleteShader(shader_vert);
    glDeleteShader(shader_frag);
}

void Shader::use()
{
    glUseProgram(id);
}

void Shader::set_float(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::compile(unsigned int shader, ShaderCompileTarget target)
{
    int success;
    char info_log[1024];

    if (target == ShaderCompileTarget::SHADER)
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, info_log);
            spdlog::error("ERR::SHADER - ", info_log);
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, nullptr, info_log);
            spdlog::error("ERR::PROGRAM - ", info_log);
        }
    }
}
