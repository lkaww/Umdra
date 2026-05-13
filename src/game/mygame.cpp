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
    if (Input::IsHeld(PSP_CTRL_LEFT))
        playerX -= playerSpeed;

    if (Input::IsHeld(PSP_CTRL_RIGHT))
        playerX += playerSpeed;

    if (Input::IsHeld(PSP_CTRL_UP))
        playerY -= playerSpeed;

    if (Input::IsHeld(PSP_CTRL_DOWN))
        playerY += playerSpeed;

    // ограничение экрана
    if (playerX < 0)
        playerX = 0;

    if (playerY < 0)
        playerY = 0;

    if (playerX > 480 - 64)
        playerX = 480 - 64;

    if (playerY > 272 - 64)
        playerY = 272 - 64;
}

void MyGame::Render(Renderer& renderer)
{
    renderer.DrawSprite(
        playerTexture,
        64,
        64,
        playerX,
        playerY
    );
}

void MyGame::Shutdown()
{
}