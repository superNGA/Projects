#include "Colision.h"

/*
try a approach with distance measured from center
make actual collision stuff work
*/

void Colision::UpdateCollision(sf::CircleShape& object, sf::RenderWindow& window)
{
	PosObj = object.getPosition();
	radius = object.getRadius();
	ScreenRes = window.getSize();

	//Y-axis check
	if (PosObj.y < (0.0f + radius) || PosObj.y >(ScreenRes.y - radius))
	{
		
		PosObj.y > ScreenRes.y / 2 ? object.move(0.0f,-((PosObj.y + radius) - ScreenRes.y)) : object.move(0.0f,((PosObj.y + radius) - ScreenRes.y));
		//printf("Collided");
	}

	//X-axis check
	if (PosObj.x < (0.0f + radius) || PosObj.x >(ScreenRes.x - radius))
	{
		PosObj.x > ScreenRes.x / 2 ? object.move(-((PosObj.x + radius) - ScreenRes.x),0.0f) : object.move(((PosObj.x + radius) - ScreenRes.x),0.0f);
		//printf("Collided");
	}

	return;
}