#include "Textset.h"

sf::Vector2f Textset::Textmaker(sf::Text& text, float X, float Y, sf::Font& font, int size)
{
	text.setPosition(X, Y);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(sf::Color::White);

	sf::Vector2f positionRETURNED;
	positionRETURNED.x = X;
	positionRETURNED.y = Y;

	return positionRETURNED;
}