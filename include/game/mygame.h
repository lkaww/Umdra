#pragma once

#include "core/game.h"
#include "graphics/texture.h"
#include "core/entity.h"


class MyGame : public Game
{
public:
    void Init(Renderer& renderer) override;
    void Update() override;
    void Render(Renderer& renderer) override;
    void Shutdown() override;
};

