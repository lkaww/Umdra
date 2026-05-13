#include "game/mygame.h"
#include "graphics/renderer.h"
#include "input/input.h"

void MyGame::Init(Renderer& renderer)
{
    playerTexture =
        renderer.LoadTexture("assets/umdra_tashit.png");
}

void MyGame::Update()
{
}

void MyGame::Render(Renderer& renderer)
{
    //Logo)

    renderer.DrawSprite(
        playerTexture,
        64,
        64,
        208,
        100
    );
}

void MyGame::Shutdown()
{
}