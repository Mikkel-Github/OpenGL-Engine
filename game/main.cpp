#include "engine.h"

int main() {
    if (!VoxelEngine::Init()) return -1;

    while (!VoxelEngine::ShouldClose()) {
        VoxelEngine::Update();
        // Add: Game::Update(), Game::Render()
        // Break condition on window close
    }

    VoxelEngine::Shutdown();
    return 0;
}
