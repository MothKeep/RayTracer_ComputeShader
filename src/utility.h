#pragma once
#include <cstdint>
#include <cstdlib>
#include <glm/glm.hpp>

struct renderCallInfo{
  alignas(4) uint32_t samplesPerPixel;
};

struct Sphere{
  alignas(16) glm::vec3 center;
  alignas(4) float radius;
  alignas(4) uint32_t materialIndex;
};

struct Material{
  alignas(4) uint32_t type;
  alignas(16) glm::vec3 value1;
  alignas(4) float value2;
};

struct SceneInfo{
  alignas(4) uint32_t spheresTotal;
  Sphere spheres[500];
  Material materials[500];
};

inline float randFloat(){
  return std::rand() / (float(RAND_MAX) + 1);
}
