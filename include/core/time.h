#pragma once

class Time
{
public:
    static void Init();
    static void Update();

    static float DeltaTime();

private:
    static unsigned long long lastTime;
    static float deltaTime;
};