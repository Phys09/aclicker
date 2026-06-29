cmake_minimum_required(VERSION 4.3.2)
project(aclicker VERSION 0.0.1 DESCRIPTION "Auto Clicker" LANGUAGES CXX)

# Set c++ standard
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Export compile commands for clangd/lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS true)


# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

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

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable("${CMAKE_PROJECT_NAME}" ./src/aclicker.cpp ./src/inputsendcore.cpp)

# Include Directories
include_directories(./include/)

# Link to the actual SDL3 library.
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE SDL3::SDL3)
