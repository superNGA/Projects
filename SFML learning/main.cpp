#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Physics.h"
#include"Input.h"
#include"Textset.h"
#include"Colision.h"

using namespace std;

int main(void)
{
	//creating main window
	sf::RenderWindow Window(sf::VideoMode(1920, 1080), "supa nigga", sf::Style::Close | sf::Style::Titlebar | sf::Style::Fullscreen);
	Window.setFramerateLimit(60); //mantains constant speed across everything
	sf::Vector2u Win_Size = Window.getSize(); //gets windows size


	//creating shape;
	sf::CircleShape Polygon(100.0f, 4);
	Polygon.setOrigin(100.0f, 100.0f);
	Polygon.setPosition((float)Win_Size.x/2, (float)Win_Size.y/2);
	Physics Player(0.0f, 0.0f, -10.0f, -10.0f);


	//F**k around variables
	int edges = 4;
	int rotation_speed = 0;
	sf::Vector2f Pos = Polygon.getPosition();
	char stats_data[50];


	//event variable
	sf::Event EventWin;
	Input input;


	//getting text display
	sf::Font Cascadia;
	if (!Cascadia.loadFromFile("D:\\PROJECTS\\SFML learning\\Fonts\\CascadiaMono.ttf")) {
		return 0;
	}
	sf::Text Xpos, Ypos, Xvel, Yvel;
	Textset stats;
	Xpos.setPosition(stats.Textmaker(Xpos, 0 ,0 ,Cascadia, 20));
	Ypos.setPosition(stats.Textmaker(Ypos, 200 ,0 ,Cascadia, 20));
	Xvel.setPosition(stats.Textmaker(Xvel, 0 ,30 ,Cascadia, 20));
	Yvel.setPosition(stats.Textmaker(Yvel, 200 ,30 ,Cascadia, 20));


	//Collision object
	Colision collision;


	while (Window.isOpen())
	{
		//getting input and executing
		input.Checkupdateandexec(Window, EventWin, edges, rotation_speed, Polygon);

		//updating physics for object
		Player.UpdatePos(Polygon);

		//Getting player position
		Pos = Polygon.getPosition();

		//checking for collision
		collision.UpdateCollision(Polygon, Window);

		//text...
		std::ostringstream stats_data;
		stats_data << "X pos : "<<fixed<< setprecision(2)<<Pos.x;//Player.Posx
		Xpos.setString(stats_data.str());
		stats_data.str("");
		stats_data.clear();
		stats_data << "Y pos : " << fixed << setprecision(2) << Pos.y;//Player.Posy
		Ypos.setString(stats_data.str());
		stats_data.str("");
		stats_data.clear();
		stats_data << "X vel : " << fixed << setprecision(2) << Player.Velx;
		Xvel.setString(stats_data.str());
		stats_data.str("");
		stats_data.clear();
		stats_data << "Y vel : " << fixed << setprecision(2) << Player.Vely;
		Yvel.setString(stats_data.str());

		//bullshit setup
		Polygon.rotate(rotation_speed);
		if (edges >= 3)
		{
			Polygon.setPointCount(edges);
		}
		else
		{
			edges = 3;
		}

		//refreshing window
		Window.clear(sf::Color::Black);

		Window.draw(Polygon);
		Window.draw(Xpos);
		Window.draw(Ypos);
		Window.draw(Xvel);
		Window.draw(Yvel);

		Window.display();
	}

	return 0;
}