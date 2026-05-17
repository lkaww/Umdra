#pragma once

#include "math/vector2.h"
#include "graphics/texture.h"

class Renderer;

class Entity
{
public:
    Entity();
    virtual ~Entity();

    virtual void Update(float dt);
    virtual void Render(Renderer& renderer);

    void SetTexture(Texture* tex);

    Vector2 position;
    Vector2 velocity;

protected:
    Texture* texture;
};