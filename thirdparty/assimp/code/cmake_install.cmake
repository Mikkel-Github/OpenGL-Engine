# Install script for directory: /Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp6.0.2" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/bin/libassimp.6.0.2.dylib"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/bin/libassimp.6.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.6.0.2.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.6.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp6.0.2" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/bin/libassimp.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/anim.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/aabb.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ai_assert.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/camera.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/color4.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/color4.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/config.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ColladaMetaData.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/commonMetaData.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/defs.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/cfileio.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/light.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/material.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/material.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/matrix3x3.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/matrix3x3.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/matrix4x4.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/matrix4x4.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/mesh.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ObjMaterial.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/pbrmaterial.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/GltfMaterial.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/postprocess.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/quaternion.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/quaternion.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/scene.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/metadata.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/texture.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/types.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/vector2.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/vector2.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/vector3.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/vector3.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/version.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/cimport.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/AssertHandler.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/importerdesc.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Importer.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/IOStream.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/IOSystem.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Logger.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/LogStream.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/NullLogger.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/cexport.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Exporter.hpp"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/DefaultIOStream.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SceneCombiner.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/fast_atof.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/qnan.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/BaseImporter.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Hash.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ParsingUtils.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/StreamReader.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/StreamWriter.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/StringComparison.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/StringUtils.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SGSpatialSort.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/GenericProperty.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SpatialSort.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SmallVector.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SmoothingGroups.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/SmoothingGroups.inl"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/StandardShapes.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/RemoveComments.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Subdivision.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Vertex.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/LineSplitter.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/TinyFormatter.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Profiler.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/LogAux.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Bitmap.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/XMLTools.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/IOStreamBuffer.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/CreateAnimMesh.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/XmlParser.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/BlobIOSystem.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/MathFunctions.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Exceptional.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/ByteSwapper.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/Users/mikkel/Documents/dev/FeatureFusion-Labs/VoxelEngine/thirdparty/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

