
#include "Window.h"
#include <SDL.h>
#include <stdexcept>

Window::Window(const char* title, int w_, int h_) : w(w_), h(h_) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        throw std::runtime_error(std::string("SDL_Init failed: ") + SDL_GetError());
    }

    win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
    if (!win) throw std::runtime_error(std::string("SDL_CreateWindow failed: ") + SDL_GetError());
}

Window::~Window() {
    if (win) SDL_DestroyWindow(win);
    SDL_Quit();
}

SDL_Window* Window::raw() const { return win; }
int Window::width() const { return w; }
int Window::height() const { return h; }
