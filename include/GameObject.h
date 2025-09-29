#pragma once
#include <memory>
#include "Texture.h"

struct Transform {
    float x = 0, y = 0;
    float sx = 1.0f, sy = 1.0f;
    float rotation = 0.0f; // degrees
};

class GameObject {
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void update(float dt) {}
    virtual void render();

    Transform transform;
    std::shared_ptr<Texture> sprite;
};
