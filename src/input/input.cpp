#include "input/input.h"

SceCtrlData Input::currentPad = {};
SceCtrlData Input::previousPad = {};

float Input::deadZone = 15.0f;

void Input::Init()
{
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    sceCtrlReadBufferPositive(&currentPad, 1);
    previousPad = currentPad;
}

void Input::Update()
{
    previousPad = currentPad;
    sceCtrlReadBufferPositive(&currentPad, 1);
}

bool Input::IsPressed(unsigned int button)
{
    return
        (currentPad.Buttons & button) &&
       !(previousPad.Buttons & button);
}

bool Input::IsHeld(unsigned int button)
{
    return (currentPad.Buttons & button);
}

bool Input::IsReleased(unsigned int button)
{
    return
       !(currentPad.Buttons & button) &&
        (previousPad.Buttons & button);
}

int Input::GetAnalogX()
{
    int value = currentPad.Lx - 128;

    if (value < deadZone && value > -deadZone)
        return 0;

    return value;
}

int Input::GetAnalogY()
{
    int value = currentPad.Ly - 128;

    if (value < deadZone && value > -deadZone)
        return 0;

    return value;
}