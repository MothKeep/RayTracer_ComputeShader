#include "vulkan.h"
#include "utility.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <glm/ext/vector_float3.hpp>
#include <iostream>

SceneInfo createScene(){
  SceneInfo Scene{};
  Scene.spheresTotal = 3;

  Scene.spheres[0].center = glm::vec3(0,-300.4,0);
  Scene.spheres[0].radius = 300.0f;
 
  Scene.spheres[1].center = glm::vec3(3,2.5,8);
  Scene.spheres[1].radius = 3.0f;
  Scene.spheres[2].center = glm::vec3(7,0.5,2);
  Scene.spheres[2].radius = 1.0f;
  
  return Scene;
}

int main(){
  renderCallInfo rInfo{};
  rInfo.samplesPerPixel = 2500;
  SceneInfo sInfo = createScene();
  
  Vulkan vulkan(rInfo, sInfo);
  
  try {
    vulkan.run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

}
