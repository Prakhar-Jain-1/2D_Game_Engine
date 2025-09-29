cmake_minimum_required(VERSION 3.10)
project(SimpleEngine CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    src/main.cpp
    src/Engine.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/Texture.cpp
    src/Scene.cpp
    src/GameObject.cpp
)

add_executable(SimpleEngine ${SRC})

# Add your project's own include directory to the target
target_include_directories(SimpleEngine PRIVATE include)

# Find the required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Link libraries using their modern imported targets.
# This single command correctly sets up include paths and links the libraries.
target_link_libraries(SimpleEngine PRIVATE
    SDL2::SDL2
    SDL2_image::SDL2_image
)