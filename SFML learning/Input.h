#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:
	void Checkupdateandexec(sf::RenderWindow& c_window, sf::Event& event, int& edges, int& rotation_speed, sf::CircleShape& object);
private:
	sf::Event c_event;
	int c_edges;
	int c_rotation_speed;
};

