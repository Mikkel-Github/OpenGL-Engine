#pragma once
#include "input/input.h"
#include <glm/glm.hpp>

class Camera {
public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    float speed;
    float fov;

    Camera();

    void update(float deltaTime, const struct Input::InputState& input);
    glm::mat4 getViewMatrix() const;
};

