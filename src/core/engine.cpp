#include "core/engine.h"
#include "input/input.h"

void Engine::Init(Game* g)
{
    running = true;
    game = g;

    Input::Init();
    renderer.Init();

    game->Init(renderer);
}

void Engine::Run()
{
    while (running)
    {
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
}