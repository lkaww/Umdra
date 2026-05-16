#pragma once

class Texture
{
public:
    Texture();
    ~Texture();

    bool Load(const char* path);

    unsigned int* GetPixels() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    unsigned int* pixels;
    int width;
    int height;
};