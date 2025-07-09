#pragma once
#include <glad/glad.h>

#include "camera.h"
namespace Graphics {
bool Init(); // Initialize renderer (shaders, buffers, etc.)
void Render(const Camera &camera); // Render a collection of objects
void Shutdown();                   // Clean up resources
} // namespace Graphics
