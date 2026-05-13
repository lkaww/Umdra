#pragma once

class Renderer;

class Game
{
public:
    virtual ~Game() = default;

    virtual void Init(Renderer& renderer)=0;
    virtual void Update()=0;

    virtual void Render(Renderer& renderer) = 0;

    virtual void Shutdown() = 0;
};