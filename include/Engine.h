#pragma once
#include <memory>
#include "Scene.h"

class Engine {
public:
    Engine(const char* title, int w, int h);
    ~Engine();

    void run();
    bool isRunning() const;

    // Accessors
    Scene& getScene();

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
