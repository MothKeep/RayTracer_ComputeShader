#pragma once
//Vulkan
#include <string>
#include <vulkan/vulkan_core.h>

//GLFW
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

//General
#include <vector>
#include <optional>
#include <set>
#include <cstdint> 
#include <limits> 
#include <algorithm> 

#include "utility.h"

#define COMPUTE_SHADER_PATH "shaders/compute.spv"
//vulkan utility
struct QueueFamilyIndices {
  std::optional<uint32_t> computeFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete() {
    return computeFamily.has_value() && presentFamily.has_value();
  }
};

struct SwapChainSupportDetails {
  VkSurfaceCapabilitiesKHR capabilities;
  std::vector<VkSurfaceFormatKHR> formats;
  std::vector<VkPresentModeKHR> presentModes;
};

//vulkan class
class Vulkan{
  public:
    Vulkan(renderCallInfo rCallInfo, SceneInfo sceneInfo);
    ~Vulkan();
    
    void run();

//==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==
  private:
    //general functions
    void initWindow();
    void initVulkan();
    void cleanup();

    //variables
    GLFWwindow* window;
    uint32_t windowWidth;
    uint32_t windowHeight;
    
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    uint32_t computeFamily;
    uint32_t presentFamily;
    VkQueue computeQueue;
    VkQueue presentQueue;

    VkSurfaceKHR surface;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;

    VkImage storageImage;
    VkDeviceMemory storageImageMemory;
    VkImageView storageImageView;

    renderCallInfo rInfo;
    VkDeviceMemory rInfoBufferMemory;
    VkBuffer rInfoBuffer;
    SceneInfo sInfo;
    VkDeviceMemory sInfoBufferMemory;
    VkBuffer sInfoBuffer;

    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;

    VkDescriptorSetLayout descriptorSetLayout;
    VkDescriptorPool descriptorPool;
    VkDescriptorSet descriptorSet;

    VkPipelineLayout pipelineLayout;
    VkPipeline pipeline;

    VkFence fence;
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    

    //functions
    void createInstance();
    std::vector<const char*> getRequiredExtensions();
    void setupDebugMessenger();
   
    void createSurface();
    

    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device); 
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();
    
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    void createSwapChain();
    void createImageView();

    void createStorageImage();
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createStorageImageView();

    void createUniformBuffers();

    VkShaderModule createShaderModule(const std::vector<char>& code);

    void createCommandPool();
    void createCommandBuffer();

    void createDescriptorSetLayout();
    void createDescriptorPool();
    void createDescriptorSet();
    
    void createPipelineLayout();
    void createPipeline();

    void createFence();
    void createSemaphores();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    VkImageMemoryBarrier getImagePipelineBarrier(
        const VkAccessFlags &srcAccessFlags, const VkAccessFlags &dstAccessFlags,
        const VkImageLayout &oldLayout, const VkImageLayout &newLayout,
        const VkImage &image);
    void render();
};
