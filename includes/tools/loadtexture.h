#pragma once
// utility function for loading a 2D texture from file
// ---------------------------------------------------

#include <stb_image.h>
#include <string>
using namespace std;

namespace Graphics {
unsigned int TextureFromFile(const char *path, const string &directory,
                             bool gamma = false);
} // namespace Graphics
