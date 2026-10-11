#include "vulkan.h"
#include "utility.h"
#include <GLFW/glfw3.h>
#include <iostream>

int main(){
  Vulkan vulkan;
  
  try {
    vulkan.run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

}
