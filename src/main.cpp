#include "Engine.h"
#include "Texture.h"
#include <SDL_image.h>
#include <bits/stdc++.h>

int main(int argc, char** argv) {
    try {
        if (IMG_Init(IMG_INIT_PNG) == 0) {
            std::cerr << "IMG_Init failed: " << IMG_GetError() << std::endl;
        }

        Engine engine("SimpleEngine", 800, 600);

        // Create a demo object
        auto obj = engine.getScene().createObject();
        // load a texture from assets/sprite.png (create an assets/ dir and add a small PNG)
        obj->sprite = std::make_shared<Texture>(SDL_GetRenderer(SDL_GetWindowFromID(1)), "../assets/sprite.png");
        obj->transform.x = 100;
        obj->transform.y = 100;

        engine.run();

        IMG_Quit();
    } catch (const std::exception& e) {
        std::cerr << "Fatal: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}