#include "vulkan.h"
#include "utility.h"
#include <GLFW/glfw3.h>
#include <cstdlib>
#include <ctime>
#include <glm/ext/vector_float3.hpp>
#include <iostream>

SceneInfo createScene(){
  SceneInfo Scene{};
  Scene.spheresTotal = 404;

  Scene.spheres[0].center = glm::vec3(0.0f, -1000.0f, 0.0f);
  Scene.spheres[0].radius = 1000.0f;
  Scene.spheres[0].materialIndex = 0;

  Scene.materials[0].type = 0; 
  Scene.materials[0].value1 = glm::vec3(0.5f, 0.5f, 0.5f);

  for (int i = -10; i < 10; i++) {
    for (int j =-10; j < 10; j++) {
      int index = 1 + (i+10) * 20 + (j+10);
      float radius = 0.16f;
      glm::vec3 center = glm::vec3(i + 0.9f * randFloat(), radius,
                                   j + 0.9f * randFloat());

      if (glm::length(center - glm::vec3(4.0f, 0.2f, 0.0f)) <= 0.9f) {
        Scene.spheres[index].radius = 0.0f;
        continue;
      }

      Scene.spheres[index].center = center;
      Scene.spheres[index].radius = radius;
      Scene.spheres[index].materialIndex = index;

      float matChoice = randFloat();

      if (matChoice < 0.8f) {
        Scene.materials[index].type = 0;
        glm::vec3 color1 = glm::vec3(randFloat(), randFloat(), randFloat());
        glm::vec3 color2 = glm::vec3(randFloat(), randFloat(), randFloat());
        Scene.materials[index].value1 = color1 * color2;
      } else if(matChoice < 0.95){
        Scene.materials[index].type = 1;
        Scene.materials[index].value1 = glm::vec3(0.5f + 0.5f * randFloat(), 0.5f + 0.5f * randFloat(), 0.5f + 0.5f * randFloat());
        Scene.materials[index].value2 = randFloat() * 0.5f;
      } else{
        Scene.materials[index].type = 2;
        Scene.materials[index].value1 = glm::vec3(0.5f + 0.5f * randFloat(), 0.5f + 0.5f * randFloat(), 0.5f + 0.5f * randFloat());
        Scene.materials[index].value2 = randFloat() * 0.6 + 1.2f;
      }
    }
  }

  int index = 401;
  Scene.spheres[index].center = glm::vec3(-4.0f, 1.0f, 0.0f);
  Scene.spheres[index].radius = 1.0f;
  Scene.spheres[index].materialIndex = index;
  Scene.materials[index].type = 0;
  Scene.materials[index].value1 = glm::vec3(0.4f, 0.2f, 0.1f);

  index = 402;
  Scene.spheres[index].center = glm::vec3(0.0f, 1.0f, 0.0f);
  Scene.spheres[index].radius = 1.0f;
  Scene.spheres[index].materialIndex = index;
  Scene.materials[index].type = 2; 
  Scene.materials[index].value1 = glm::vec3(1.0f);
  Scene.materials[index].value2 = 1.5f;

  index = 403;
  Scene.spheres[index].center = glm::vec3(4.0f, 1.0f, 0.0f);
  Scene.spheres[index].radius = 1.0f;
  Scene.spheres[index].materialIndex = index;
  Scene.materials[index].type = 1;
  Scene.materials[index].value1 = glm::vec3(0.7f, 0.6f, 0.5f);
  Scene.materials[index].value2 = 0.1f; 
  
  return Scene;
}

int main(){
  renderCallInfo rInfo{};
  rInfo.samplesPerPixel = 225;
  std::srand(time(0));
  SceneInfo sInfo = createScene();
  
  Vulkan vulkan(rInfo, sInfo);
  
  try {
    vulkan.run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

}
