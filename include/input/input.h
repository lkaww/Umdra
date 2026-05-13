#pragma once

#include <pspctrl.h>

class Input
{
public:
    static void Init();
    static void Update();

    static bool IsPressed(unsigned int button);
    static bool IsHeld(unsigned int button);
    static bool IsReleased(unsigned int button);

    static int GetAnalogX();
    static int GetAnalogY();

private:
    static SceCtrlData currentPad;
    static SceCtrlData previousPad;
};