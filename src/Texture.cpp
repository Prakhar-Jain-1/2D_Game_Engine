#include "Texture.h"
#include <SDL_image.h>
#include <stdexcept>
#include <bits/stdc++.h>

Texture::Texture(SDL_Renderer* renderer_, const std::string& path) : renderer(renderer_) {
    SDL_Surface* surf = IMG_Load(path.c_str());
    if (!surf) {
        throw std::runtime_error(std::string("IMG_Load failed: ") + IMG_GetError());
    }
    tex = SDL_CreateTextureFromSurface(renderer, surf);
    w = surf->w; h = surf->h;
    SDL_FreeSurface(surf);
    if (!tex) throw std::runtime_error(std::string("SDL_CreateTextureFromSurface failed: ") + SDL_GetError());
}

Texture::~Texture() { if (tex) SDL_DestroyTexture(tex); }

void Texture::draw(int x, int y, int width, int height) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = (width == 0) ? w : width;
    dest.h = (height == 0) ? h : height;
    SDL_RenderCopy(renderer, tex, nullptr, &dest);
}
int Texture::width() const { return w; }
int Texture::height() const { return h; }
