#pragma once
#include <cstdint>
#include <glm/glm.hpp>

struct renderCallInfo{
  alignas(4) uint32_t samplesPerPixel;
};

struct Sphere{
  alignas(16) glm::vec3 center;
  alignas(4) float radius;
};

struct SceneInfo{
  alignas(4) uint32_t spheresTotal;
  Sphere spheres[100];
};
