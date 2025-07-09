#pragma once

#include <GLFW/glfw3.h>


namespace Input {

    struct InputState {
        bool moveForward = false;
        bool moveBackward = false;
        bool moveLeft = false;
        bool moveRight = false;
        float yaw = -90.0f;
        float pitch = 0.0f;
        float zoom = 0.0f;
    };

    void processInput(GLFWwindow* window);
    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    const InputState& getState();
}
