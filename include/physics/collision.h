#pragma once

#include "math/rect.h"

class Collision
{
public:
    static bool Intersects(
        const Rect& a,
        const Rect& b
    );
};