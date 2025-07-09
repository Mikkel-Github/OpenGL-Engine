#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "input/input.h"

Camera::Camera()
    : position(0.0f, 0.0f, 3.0f),
      front(0.0f, 0.0f, -1.0f),
      up(0.0f, 1.0f, 0.0f),
      speed(2.5f) {}

void Camera::update(float deltaTime, const Input::InputState& input) {
    float velocity = speed * deltaTime;
    glm::vec3 right = glm::normalize(glm::cross(front, up));
        
    // Camera Movement
    if (input.moveForward)
        position += front * velocity;
    if (input.moveBackward)
        position -= front * velocity;
    if (input.moveLeft)
        position -= right * velocity;
    if (input.moveRight)
        position += right * velocity;

    // Camera Rotation
    glm::vec3 direction;
    direction.x = cos(glm::radians(input.yaw)) * cos(glm::radians(input.pitch));
    direction.y = sin(glm::radians(input.pitch));
    direction.z = sin(glm::radians(input.yaw)) * cos(glm::radians(input.pitch));
    front = glm::normalize(direction);


    // Camera Zoom
    fov = 65.0f - (55 * input.zoom);
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

