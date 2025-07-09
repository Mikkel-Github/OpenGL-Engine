#include "input.h"



namespace Input {
    static InputState currentState;
    float lastX = 640.0f, lastY = 360.0f;
    bool firstMouse = true;

    void processInput(GLFWwindow *window) {
        currentState.moveForward  = glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
        currentState.moveBackward = glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
        currentState.moveLeft     = glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
        currentState.moveRight    = glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
        float xpos = static_cast<float>(xposIn);
        float ypos = static_cast<float>(yposIn);

        if(firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }
        

        float offsetX = xpos - lastX;
        float offsetY = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        const float sensitivity = 0.1f;
        offsetX *= sensitivity;
        offsetY *= sensitivity;

        currentState.yaw += offsetX;
        currentState.pitch += offsetY;

        if(currentState.pitch > 89.0f)
            currentState.pitch = 89.0f;
        if(currentState.pitch < -89.0f)
            currentState.pitch = -89.0f;
    }

    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
        currentState.zoom -= (float)yoffset;
        if(currentState.zoom < 0.0f)
            currentState.zoom = 0.0f;
        if(currentState.zoom > 1.0f)
            currentState.zoom = 1.0f;
    }

    const InputState& getState() {
        return currentState;
    }
}
