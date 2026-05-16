#pragma once

#include "graphics/texture.h"

class Renderer
{
public:
    void Init();
    void BeginFrame();

    unsigned int* LoadTexture(const char* path);

    void DrawSprite(
        const Texture& texture,
        float x,
        float y
    );

    void EndFrame();
    void Shutdown();
};