# 2D_Game_Engine

# Starter 2D Game Engine (C++ / SDL2)

This project is a small, well-commented starter 2D game engine using SDL2 (and SDL_image).
It includes a simple engine loop, window/renderer wrappers, basic scene & game object classes,
and a texture helper. Use this as a foundation to add physics, input mapping, audio, scripting, etc.

---

# Build / Requirements

- Requires: C++17 (or later), CMake, SDL2, SDL2_image
- On Ubuntu/Debian: sudo apt install libsdl2-dev libsdl2-image-dev cmake build-essential
- Build steps:
  mkdir build && cd build
  cmake ..
  cmake --build .
  ./SimpleEngine
---

# Notes & Next steps

- The starter demonstrates a simple engine loop and modular structure. The Texture constructor expects a valid SDL_Renderer — in a more robust setup you'd pass the engine's renderer instance when constructing textures.
- Add input handling, resource manager (to avoid reloading textures), an entity-component-system (ECS) or lightweight component model, audio (SDL_mixer), collision, physics, tilemap, and scripting support.
- Consider switching to a library like SFML if you prefer a slightly higher-level C++ API, or use GLFW + OpenGL for accelerated sprite batching.

Happy hacking — edit files in the canvas to start extending the engine.
