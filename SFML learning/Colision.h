#pragma once
#include<SFML/Graphics.hpp>
class Colision
{
public:
	void UpdateCollision(sf::CircleShape& object, sf::RenderWindow& window);
private:
	sf::Vector2f PosObj;
	sf::Vector2u ScreenRes;
	float radius;
};

