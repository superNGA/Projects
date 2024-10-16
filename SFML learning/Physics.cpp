#include "Physics.h"

Physics::Physics(float I_Velx, float I_Vely, float Acc_Vertical_Gravity, float Acc_Horizontal_Gravity)
{
	Velx = I_Velx;
	Vely = I_Vely;
	Gx = Acc_Vertical_Gravity * GravityMultiplier;
	Gy = Acc_Horizontal_Gravity * GravityMultiplier;
}

void Physics::UpdatePos(sf::CircleShape& Object)
{
	//getting distance to move in 1 frame
	Posx = Velx * Timeperframe;
	Posy = Vely * Timeperframe;

	//moving object
	Object.move(Posy, Posx);

	//updating velocity
	Velx += Gx * Timeperframe;
	Vely += Gy * Timeperframe;

	return;
}
