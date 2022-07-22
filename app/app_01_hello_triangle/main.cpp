#include <iostream>
#include "core/engine.h"
#include "spdlog/spdlog.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

int main()
{
    Engine engine{"app_01_hello_trinagle", 800, 600};
    engine.loop = [&]()
    {
        glClearColor(0.08f, 0.294f, 0.368f, 1.0f); // eden color #164b5e
        glClear(GL_COLOR_BUFFER_BIT);
    };
    engine.on_input = [](GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    };

    if (!engine.can_start())
    {
        spdlog::error("Failed to start engine");
        return -1;
    }

    engine.start_loop();

    return 0;
}
