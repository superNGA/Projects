#pragma once
#ifndef PHYSICS_
#define PHYSICS_H

#include <SFML/Graphics.hpp>

class Physics
{
public:
	float Velx;
	float Vely;
	float Gx;
	float Gy;
	float Timeperframe = 1.0f / 60.0f;
	float Posx;
	float Posy;
	float GravityMultiplier = 20.0f;
	Physics(float I_Velx, float I_Vely, float Acc_Vertical_Gravity, float Acc_Horizontal_Gravity); //main entry for class
	void UpdatePos(sf::CircleShape& Object);
private:
	//add constant variables here...
};

#endif 