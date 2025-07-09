#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Platform {
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    bool InitWindow(const char* title, int width, int height);
    GLFWwindow* GetWindow();
    void PollEvents();
    void SwapBuffers();
    bool ShouldClose();
    void ShutdownWindow();
}

