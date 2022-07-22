#pragma once

#include <string>
#include <functional>

class GLFWwindow;

class Engine
{
public:
    Engine(const std::string &win_title, unsigned int win_width, unsigned int win_height);
    ~Engine();
    bool can_start() const;
    void start_loop();
    std::string get_shader_dir() const;
    std::function<void()> on_before_start;
    std::function<void()> loop;
    std::function<void(GLFWwindow *)> on_input;

private:
    std::string app_name;
    bool glad_loaded = false;
    GLFWwindow *window = nullptr;
};
