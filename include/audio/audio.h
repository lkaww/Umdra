#pragma once

class Audio
{
public:
    static void Init();

    static bool LoadWav(const char* path);

    static void Play();

    static void Shutdown();

private:
    static int channel;

    static short* wavBuffer;
    static int wavSamples;
};