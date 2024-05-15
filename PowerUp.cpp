#include "PowerUp.h"
#include "Ship.h"
const float PowerUp::PI{ 3.14f };

/*
PowerUp::PowerUp():RandomFallingObject()
{
sprite.dimensions.height = 2 * sprite.dimensions.radius;
sprite.dimensions.width = 2 * sprite.dimensions.radius;
velocity.y = sprite.dimensions.width*sprite.dimensions.height / 10.0;
}

bool PowerUp::update(Ship & player, Object::Command command)
{
sprite.position.y += velocity.y;
if (sprite.position.y >= screenHeight)
{
if (collides(player))
{

}
return false;
}
else
{
colorize();
return true;
}
}
*/
