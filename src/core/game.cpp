#include "core/game.h"
#include "graphics/renderer.h"

class MyGame : public Game
{
public:
    void Init() override
    {
    }

    void Update() override
    {
    }

    void Render() override
    {
        Renderer r;
        r.DrawSprite(208, 104);
    }

    void Shutdown() override
    {
    }
};