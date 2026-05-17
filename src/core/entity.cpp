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