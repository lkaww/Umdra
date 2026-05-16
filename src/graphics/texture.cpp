#include "graphics/texture.h"

#include <cstdio>
#include <cstdlib>
#include <malloc.h>
#include <png.h>

Texture::Texture()
{
    pixels = nullptr;
    width = 0;
    height = 0;
}

Texture::~Texture()
{
    if (pixels)
        free(pixels);
}

bool Texture::Load(const char* path)
{
    FILE* fp = fopen(path, "rb");
    if (!fp)
        return false;

    png_structp png =
        png_create_read_struct(
            PNG_LIBPNG_VER_STRING,
            nullptr,
            nullptr,
            nullptr);

    png_infop info =
        png_create_info_struct(png);

    png_init_io(png, fp);
    png_read_info(png, info);

    width = png_get_image_width(png, info);
    height = png_get_image_height(png, info);

    png_set_expand(png);
    png_set_strip_16(png);
    png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

    png_read_update_info(png, info);

    pixels = (unsigned int*)memalign(
        16,
        width * height * 4
    );

    png_bytep* rows =
        (png_bytep*)malloc(
            sizeof(png_bytep) * height
        );

    for (int y = 0; y < height; y++)
        rows[y] =
            (png_bytep)(pixels + y * width);

    png_read_image(png, rows);

    free(rows);

    png_destroy_read_struct(
        &png,
        &info,
        nullptr
    );

    fclose(fp);

    return true;
}

unsigned int* Texture::GetPixels() const
{
    return pixels;
}

int Texture::GetWidth() const
{
    return width;
}

int Texture::GetHeight() const
{
    return height;
}