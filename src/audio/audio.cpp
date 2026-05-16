#include "audio/audio.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <pspaudio.h>

int Audio::channel = -1;

short* Audio::wavBuffer = nullptr;
int Audio::wavSamples = 0;

struct WavHeader
{
    char riff[4];
    int size;
    char wave[4];

    char fmt[4];
    int fmtSize;
    short format;
    short channels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;

    char data[4];
    int dataSize;
};

void Audio::Init()
{
    channel = sceAudioChReserve(
        PSP_AUDIO_NEXT_CHANNEL,
        1024,
        PSP_AUDIO_FORMAT_MONO
    );
}

bool Audio::LoadWav(const char* path)
{
    FILE* file = fopen(path, "rb");
    if (!file)
        return false;

    char id[4];
    int size;

    fread(id, 1, 4, file);
    fread(&size, 4, 1, file);

    if (strncmp(id, "RIFF", 4) != 0)
    {
        fclose(file);
        return false;
    }

    fread(id, 1, 4, file);

    if (strncmp(id, "WAVE", 4) != 0)
    {
        fclose(file);
        return false;
    }

    bool foundData = false;
    int dataSize = 0;

    while (!feof(file))
    {
        fread(id, 1, 4, file);
        fread(&size, 4, 1, file);

        if (strncmp(id, "data", 4) == 0)
        {
            dataSize = size;
            foundData = true;
            break;
        }

        fseek(file, size, SEEK_CUR);
    }

    if (!foundData)
    {
        fclose(file);
        return false;
    }

    wavSamples = dataSize / 2;

    wavBuffer = (short*)malloc(dataSize);

    fread(wavBuffer, dataSize, 1, file);

    fclose(file);

    return true;
}

void Audio::Play()
{
    if (!wavBuffer)
        return;

    int offset = 0;

    while (offset < wavSamples)
    {
        int chunk = 1024;

        if (offset + chunk > wavSamples)
            chunk = wavSamples - offset;

        sceAudioOutputBlocking(
            channel,
            PSP_AUDIO_VOLUME_MAX,
            wavBuffer + offset
        );

        offset += chunk;
    }
}

void Audio::Shutdown()
{
    if (wavBuffer)
    {
        free(wavBuffer);
        wavBuffer = nullptr;
    }

    if (channel >= 0)
    {
        sceAudioChRelease(channel);
        channel = -1;
    }
}