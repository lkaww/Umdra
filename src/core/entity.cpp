#include "core/entity.h"
#include "graphics/renderer.h"

Entity::Entity()
{
    texture = nullptr;
}

Entity::~Entity()
{
}

void Entity::Update(float dt)
{
    position += velocity * dt;
}

void Entity::Render(Renderer& renderer)
{
    if (texture)
    {
        renderer.DrawSprite(
            *texture,
            position.x,
            position.y
        );
    }
}

void Entity::SetTexture(Texture* tex)
{
    texture = tex;
}

void Entity::SetHitbox(float w, float h)
{
    hitbox.x = w;
    hitbox.y = h;
}

Rect Entity::GetBounds(float dt) const
{
    if (!texture)
        return Rect();

    return Rect(
        position.x + velocity.x * dt,
        position.y + velocity.y * dt,
        hitbox.x,
        hitbox.y
    );
}