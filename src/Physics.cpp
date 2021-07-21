#include "Physics.h"

float Physics::DegToRad(float angle)
{
    //return 2 * M_PI * (angle / 360);
	return (angle) * M_PI / 180.0;
}

float Physics::Clamp(float min, float max, float val)
{
	if (val < min)
		val = min;
	else if (val > max)
		val = max;
	return val;
}

sf::Vector2f Physics::WrapCoordinates(sf::Vector2f pos, sf::Vector2f size)
{
	sf::Vector2f res = pos;
	
	if (pos.x + size.x/2.0f < 0.0f)
		res.x = SCREEN_WIDTH + size.x/2.0f;
	else if (pos.x - size.x/2.0f > SCREEN_WIDTH)
		res.x = -(size.x/2.0f);

	if (pos.y + size.y/2.0f < 0.0f)
		res.y = SCREEN_HEIGHT + size.y/2.0f;
	else if (pos.y - size.y/2.0f > SCREEN_HEIGHT)
		res.y = -(size.y/2.0f);

	return res;
}
