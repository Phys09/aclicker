cmake_minimum_required(VERSION 4.3.2)
project(aclicker VERSION 0.0.1 DESCRIPTION "Auto Clicker" LANGUAGES CXX)

# Set c++ standard
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Export compile commands for clangd/lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS true)


# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

include(FetchContent)

# sdl3 + vulkan as imgui backend
FetchContent_Declare(
  sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG origin/main
)

# imgui user interface | docking branch for docking support
FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG origin/docking
)

FetchContent_MakeAvailable(sdl3 imgui)

# Create your game executable target as usual
add_executable("${CMAKE_PROJECT_NAME}"
  ./src/aclicker.cpp
  ./src/inputsendcore.cpp
)

# Include Directories for main project
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
  "${imgui_SOURCE_DIR}"
  "${imgui_SOURCE_DIR}/backends"
  "./include/"
)

# 0. Fetchcontent of imgui, and use <subproject>_SOURCE_DIR to extract *h and *cpp files
# 1. Create imgui static library target (against recommendations of the quick start guide)
# 2. Link cpp and h files to imgui target
# Imgui cpp files
file(GLOB IMGUI_SOURCES
  ${imgui_SOURCE_DIR}/*.cpp
)

# Backends
set(IMGUI_BACKEND_SOURCES
  ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
  ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)

# Create imgui target
add_library(imgui STATIC ${IMGUI_SOURCES} ${IMGUI_BACKEND_SOURCES})

# Configure imgui include directories
target_include_directories(imgui PUBLIC
  ${imgui_SOURCE_DIR}
  ${imgui_SOURCE_DIR}/backends
)

# Link to the actual SDL3 library.
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SDL3::SDL3)

# Find and Link to Vulkan
find_package(Vulkan)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Vulkan)

message(STATUS "imgui_headers: ${imgui_headers}")
message(STATUS "imgui_src: ${imgui_src}")

message(STATUS "imgui_source_dir: ${imgui_SOURCE_DIR}")
message(STATUS "sdl3_source_dir: ${SDL3_SOURCE_DIR}")

