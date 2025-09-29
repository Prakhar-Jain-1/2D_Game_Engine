
#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class Scene {
public:
    Scene() = default;
    ~Scene() = default;

    void update(float dt);
    void render();

    std::shared_ptr<GameObject> createObject();

private:
    std::vector<std::shared_ptr<GameObject>> objects;
};
