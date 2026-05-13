#include <pspkernel.h>

#include "core/engine.h"
#include "game/mygame.h"

PSP_MODULE_INFO("Umdra", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER);

int main()
{
    MyGame game;
    Engine engine;

    engine.Init(&game);
    engine.Run();
    engine.Shutdown();

    return 0;
}