#include "Renderer.h"
#include <stdexcept>

Renderer::Renderer(SDL_Window* window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) throw std::runtime_error(std::string("SDL_CreateRenderer failed: ") + SDL_GetError());
}
Renderer::~Renderer() { if (renderer) SDL_DestroyRenderer(renderer); }

SDL_Renderer* Renderer::raw() const { return renderer; }
void Renderer::clear() { SDL_RenderClear(renderer); }
void Renderer::present() { SDL_RenderPresent(renderer); }
void Renderer::setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { SDL_SetRenderDrawColor(renderer, r, g, b, a); }
