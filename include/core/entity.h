#pragma once

#include "math/vector2.h"
#include "math/rect.h"
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
    void SetHitbox(float w, float h);

    Rect GetBounds(float dt) const;

    Vector2 position;
    Vector2 velocity;

protected:
    Texture* texture;
    Vector2 hitbox;
};