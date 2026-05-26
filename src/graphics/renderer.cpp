#include "graphics/renderer.h"
#include "graphics/texture.h"

#include <cstdio>
#include <cstdlib>
#include <malloc.h>

#include <png.h>

#include <pspdisplay.h>
#include <pspgu.h>

#include <pspdebug.h>

static unsigned int list[262144] __attribute__((aligned(16)));

struct Vertex
{
    float u, v;
    unsigned int color;
    float x, y, z;
};

unsigned int* Renderer::LoadTexture(const char* path)
{
    FILE* fp = fopen(path, "rb");
    if (!fp)
        return nullptr;

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

    int width  = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);

    png_set_expand(png);
    png_set_strip_16(png);
    png_set_add_alpha(png, 0xFF, PNG_FILLER_AFTER);

    png_read_update_info(png, info);

    unsigned int* texture =
        (unsigned int*)memalign(
            16,
            width * height * 4);

    png_bytep* rows =
        (png_bytep*)malloc(sizeof(png_bytep) * height);

    for (int y = 0; y < height; y++)
        rows[y] =
            (png_bytep)(texture + y * width);

    png_read_image(png, rows);

    free(rows);

    png_destroy_read_struct(
        &png,
        &info,
        nullptr);

    fclose(fp);

    return texture;
}

void Renderer::Init()
{
    pspDebugScreenInit();

    sceGuInit();

    sceGuStart(GU_DIRECT, list);

    sceGuDrawBuffer(GU_PSM_8888, (void*)0, 512);
    sceGuDispBuffer(480, 272, (void*)0x88000, 512);
    sceGuDepthBuffer((void*)0x110000, 512);

    sceGuOffset(2048 - 240, 2048 - 136);
    sceGuViewport(2048, 2048, 480, 272);

    sceGuEnable(GU_SCISSOR_TEST);
    sceGuScissor(0, 0, 480, 272);

    sceGuFinish();
    sceGuSync(0, 0);

    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

void Renderer::BeginFrame()
{
    sceGuStart(GU_DIRECT, list);

    sceGuClearColor(0x000000);
    sceGuClear(
        GU_COLOR_BUFFER_BIT |
        GU_DEPTH_BUFFER_BIT
    );
}

void Renderer::DrawSprite(
    const Texture& texture,
    float x,
    float y)
{
    sceGuEnable(GU_TEXTURE_2D);

    sceGuTexMode(GU_PSM_8888, 0, 0, 0);

    sceGuTexImage(
        0,
        texture.GetWidth(),
        texture.GetHeight(),
        texture.GetWidth(),
        texture.GetPixels()
    );

    Vertex* v =
        (Vertex*)sceGuGetMemory(
            2 * sizeof(Vertex));

    v[0] =
    {
        0.0f,
        0.0f,
        0xFFFFFFFF,
        x,
        y,
        0.0f
    };

    v[1] =
    {
        (float)texture.GetWidth(),
        (float)texture.GetHeight(),
        0xFFFFFFFF,
        x + texture.GetWidth(),
        y + texture.GetHeight(),
        0.0f
    };

    sceGuDrawArray(
        GU_SPRITES,
        GU_TEXTURE_32BITF |
        GU_COLOR_8888 |
        GU_VERTEX_32BITF |
        GU_TRANSFORM_2D,
        2,
        0,
        v
    );
}

void Renderer::EndFrame()
{
    sceGuFinish();
    sceGuSync(0, 0);

    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

void Renderer::Shutdown()
{
    sceGuTerm();
}