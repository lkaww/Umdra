#include "core/time.h"

#include <pspkernel.h>

unsigned long long Time::lastTime = 0;
float Time::deltaTime = 0.0f;

void Time::Init()
{
    lastTime = sceKernelGetSystemTimeWide();
}

void Time::Update()
{
    unsigned long long current =
        sceKernelGetSystemTimeWide();

    deltaTime =
        (current - lastTime) / 1000000.0f;

    lastTime = current;
}

float Time::DeltaTime()
{
    return deltaTime;
}