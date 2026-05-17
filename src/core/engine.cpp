#include "core/engine.h"
#include "input/input.h"
#include "audio/audio.h"
#include "core/time.h"

void Engine::Init(Game* g)
{
    running = true;
    game = g;

    Time::Init();

    Input::Init();

    renderer.Init();
    game->Init(renderer);

    Audio::Init();
}

void Engine::Run()
{
    while (running)
    {
        Time::Update();
        Input::Update();

        if (Input::IsPressed(PSP_CTRL_START))
            running = false;

        game->Update();

        renderer.BeginFrame();
        game->Render(renderer);
        renderer.EndFrame();
    }
}

void Engine::Shutdown()
{
    game->Shutdown();
    renderer.Shutdown();
    Audio::Shutdown();
}