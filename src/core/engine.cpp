#include "engine.h"
#include "spdlog/spdlog.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Engine::Engine(const std::string &win_title, unsigned int win_width, unsigned int win_height)
{
    // initialize glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create window
    window = glfwCreateWindow(win_width, win_height, win_title.c_str(), nullptr, nullptr);
    if (!window)
    {
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow *window, int width, int height)
                                   { glViewport(0, 0, width, height); });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return;
    }

    glad_loaded = true;
}

Engine::~Engine()
{
    if (window)
    {
        glfwTerminate();
    }
}

bool Engine::can_start() const
{
    return window != nullptr && glad_loaded;
}

void Engine::start_loop()
{
    while (!glfwWindowShouldClose(window))
    {
        if (on_input)
        {
            on_input(window);
        }

        if (loop)
        {
            loop();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
