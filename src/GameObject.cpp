#include "GameObject.h"
#include <SDL.h>

void GameObject::render() {
    if (sprite) {
        sprite->draw(static_cast<int>(transform.x), static_cast<int>(transform.y));
    }
}
