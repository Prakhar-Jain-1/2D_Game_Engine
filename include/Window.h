#pragma once
#include <SDL.h>
#include <string>

class Window {
public:
    Window(const char* title, int w, int h);
    ~Window();

    SDL_Window* raw() const;
    int width() const;
    int height() const;
private:
    SDL_Window* win = nullptr;
    int w = 0, h = 0;
};
