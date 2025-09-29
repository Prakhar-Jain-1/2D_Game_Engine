#pragma once
#include <SDL.h>
#include <memory>

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    SDL_Renderer* raw() const;
    void clear();
    void present();
    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a=255);

private:
    SDL_Renderer* renderer = nullptr;
};