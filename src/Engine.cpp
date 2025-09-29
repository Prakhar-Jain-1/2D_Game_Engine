
#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include <SDL.h>
#include <bits/stdc++.h>

struct Engine::Impl {
    Impl(const char* title, int w, int h)
    : window(title, w, h), renderer(window.raw()), running(true) {}

    Window window;
    Renderer renderer;
    Scene scene;
    bool running = false;
};

Engine::Engine(const char* title, int w, int h)
: impl(std::make_unique<Impl>(title, w, h))
{
    impl->running = true;
}

Engine::~Engine() = default;

void Engine::run() {
    const float dt = 1.0f / 60.0f;
    Uint32 last = SDL_GetTicks();

    while (impl->running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) impl->running = false;
        }

        Uint32 now = SDL_GetTicks();
        float elapsed = (now - last) / 1000.0f;
        last = now;

        // update
        impl->scene.update(elapsed);

        // render
        impl->renderer.clear();
        impl->scene.render();
        impl->renderer.present();

        SDL_Delay(1);
    }
}

bool Engine::isRunning() const { return impl->running; }
Scene& Engine::getScene() { return impl->scene; }