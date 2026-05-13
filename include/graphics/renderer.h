#pragma once

class Renderer
{
public:
    void Init();
    void BeginFrame();

    unsigned int* LoadTexture(const char* path);

    void DrawSprite(
        unsigned int* texture,
        int width,
        int height,
        float x,
        float y
    );

    void EndFrame();
    void Shutdown();
};