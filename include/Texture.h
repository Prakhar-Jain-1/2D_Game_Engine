#pragma once
#include <SDL.h>
#include <string>

class Texture {
public:
    Texture(SDL_Renderer* renderer, const std::string& path);
    ~Texture();

    void draw(int x, int y, int w = 0, int h = 0);
    int width() const;
    int height() const;
private:
    SDL_Texture* tex = nullptr;
    SDL_Renderer* renderer = nullptr;
    int w = 0, h = 0;
};