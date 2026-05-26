#include "game/mygame.h"
#include "graphics/renderer.h"
#include "input/input.h"
#include "audio/audio.h"
#include "core/time.h"
#include "physics/collision.h"

void MyGame::Init(Renderer& renderer)
{
    playerTexture.Load("assets/umdra_tashit.png");

    playerSpeed = 175.0f;

    player.SetHitbox(64, 64);
    player.SetTexture(&playerTexture);

    stone.SetHitbox(64, 64);
    stone.SetTexture(&playerTexture);

    player.position = Vector2(208, 200);
    stone.position = Vector2(100, 150);
}

void MyGame::Update()
{
    float dt = Time::DeltaTime();

    player.velocity = Vector2(Input::GetAnalogX(), Input::GetAnalogY());

    player.Update(dt);
    stone.Update(dt);
}

void MyGame::Render(Renderer& renderer)
{
    player.Render(renderer);
    stone.Render(renderer);
}

void MyGame::Shutdown()
{
}