#pragma once

#include "graphics/renderer.h"
#include "core/game.h"

class Engine
{
public:
    void Init(Game* game);
    void Run();
    void Shutdown();

private:
    bool running;
    Game* game;
    Renderer renderer;
};