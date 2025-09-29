#include "Scene.h"

std::shared_ptr<GameObject> Scene::createObject() {
    auto obj = std::make_shared<GameObject>();
    objects.push_back(obj);
    return obj;
}

void Scene::update(float dt) {
    for (auto& o : objects) o->update(dt);
}
void Scene::render() {
    for (auto& o : objects) o->render();
}