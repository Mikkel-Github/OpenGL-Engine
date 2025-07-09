#include "engine.h"

#include "platform/window.h"
#include "graphics/renderer.h"
#include "input/input.h"
#include "entities/camera.h"

namespace {
    Camera camera;
    float lastFrameTime = 0.0f;
}

namespace VoxelEngine {
    bool Init() {
        if (!Platform::InitWindow("Voxel Game", 1280, 720)) return false;

        // Get framebuffer size (not window size — on HiDPI screens they differ)
        int width, height;
        glfwGetFramebufferSize(Platform::GetWindow(), &width, &height);
        glViewport(0, 0, width, height);  //  Set initial viewport
                                          
        Graphics::Init(); // Init GL, load shaders
                          
        glfwSetInputMode(Platform::GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetCursorPosCallback(Platform::GetWindow(), Input::mouse_callback);
        glfwSetScrollCallback(Platform::GetWindow(), Input::scroll_callback);

        return true;
    }

    void Update() {
        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrameTime;
        lastFrameTime = currentFrame;


        // Handle input
        Input::processInput(Platform::GetWindow());

        // Update camera
        camera.update(deltaTime, Input::getState());

        // Graphics::Clear();
        Graphics::Render(camera);

        // Game update and rendering hooks here
        Platform::SwapBuffers();
        Platform::PollEvents();
    }

    bool ShouldClose() {
        return Platform::ShouldClose();
    }

    void Shutdown() {
        // Graphics::Shutdown();
        Platform::ShutdownWindow();
    }
}
