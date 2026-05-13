#pragma once

#include "core/game.h"

class MyGame : public Game
{
public:
    void Init(Renderer& renderer) override;
    void Update() override;
    void Render(Renderer& renderer) override;
    void Shutdown() override;

private:
    unsigned int* playerTexture = nullptr;

    float playerX = 208.0f;
    float playerY = 104.0f;

    float playerSpeed = 2.0f;
};