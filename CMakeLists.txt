cmake_minimum_required(VERSION 3.16)
project(VoxelGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(dBUILD_SHARED_LIBS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
endif()

# Glad must come before anything that links to it
add_library(glad STATIC thirdparty/glad/src/glad.c)
target_include_directories(glad PUBLIC thirdparty/glad/include)

# GLFW and Assimp
add_subdirectory(thirdparty/glfw)

# Avoid linking to system zlib (which causes issues on macOS/Homebrew)
set(ASSIMP_BUILD_ZLIB OFF)
set(ASSIMP_BUILD_MINIZIP ON)
set(ASSIMP_NO_EXPORT ON)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(thirdparty/assimp)

# Assimp build options
# set(BUILD_SHARED_LIBS OFF)
# set(ASSIMP_BUILD_ZLIB ON CACHE BOOL "Use internal zlib" FORCE)
# find_package(ZLIB REQUIRED)
# set(ASSIMP_BUILD_MINIZIP OFF CACHE BOOL "Disable minizip" FORCE)
# set(ASSIMP_NO_EXPORT ON)
# set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
# set(ASSIMP_BUILD_TESTS OFF)
# set(ASSIMP_INJECT_DEBUG_POSTFIX OFF)
# add_subdirectory(thirdparty/assimp)

# Root directory header
configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

# Engine source files
set(ENGINE_SRC
    engine/engine.cpp
    engine/engine.h
    engine/platform/window.cpp
    engine/platform/window.h
    engine/input/input.cpp
    engine/input/input.h
    engine/graphics/renderer.cpp
    engine/graphics/renderer.h
    engine/entities/camera.h
    engine/entities/camera.cpp
    includes/tools/loadtexture.h
    includes/tools/loadtexture.cpp
)

add_library(engine STATIC ${ENGINE_SRC})
target_include_directories(engine PUBLIC
    engine
    engine/platform
    engine/input
    engine/graphics
    thirdparty/glad/include
    thirdparty/glfw/include
    thirdparty/glm
    thirdparty/stb
    thirdparty/assimp/include
    includes
    engine/entities
    configuration
)
target_link_libraries(engine glad glfw assimp)

# Game executable
set(GAME_SRC game/main.cpp)
add_executable(game ${GAME_SRC})
target_link_libraries(game engine)
