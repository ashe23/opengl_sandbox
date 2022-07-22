#pragma once

#include <string>

enum class ShaderCompileTarget
{
    SHADER,
    PROGRAM
};

class Shader
{
public:
    Shader(const std::string &shader_dir, const std::string &shader_file_name);
    unsigned int id;

    void use();
    void set_float(const std::string &name, float value) const;

private:
    void compile(unsigned int shader, ShaderCompileTarget target);
};
