#include "Input.h"

void Input::Checkupdateandexec(sf::RenderWindow& c_Window, sf::Event& event, int& edges, int& rotation_speed, sf::CircleShape& object)
{
	while (c_Window.pollEvent(c_event))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			c_Window.close();
		}
		if (c_event.type == sf::Event::Closed)
		{
			c_Window.close();
		}
		if (c_event.type == sf::Event::KeyPressed)
		{
			if (c_event.key.code == sf::Keyboard::Space)
			{
				edges++;
			}
			if (c_event.key.code == sf::Keyboard::Return)
			{
				edges--;
			}
			if (c_event.key.code == sf::Keyboard::A)
			{
				rotation_speed--;
			}
			if (c_event.key.code == sf::Keyboard::D)
			{
				rotation_speed++;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i Mousepos = sf::Mouse::getPosition(c_Window);
			object.setPosition((float)Mousepos.x, (float)Mousepos.y);
		}
	}
}