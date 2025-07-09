#include "window.h"
#include <iostream>

static GLFWwindow* window = nullptr;

namespace Platform {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

bool InitWindow(const char* title, int width, int height) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW.\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on macOS
#endif

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window.\n";
        glfwTerminate();
        return false;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD.\n";
        return false;
    }

    glViewport(0, 0, width, height);
    return true;
}

GLFWwindow* GetWindow() {
    return window;
}

void PollEvents() {
    glfwPollEvents();
}

void SwapBuffers() {
    glfwSwapBuffers(window);
}

bool ShouldClose() {
    return glfwWindowShouldClose(window);
}

void ShutdownWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

}

