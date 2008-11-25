#ifndef PLAYER_H
#define PLAYER_H

#include "base.h"

class Player : public Graphic {
private:
	Color *base_color;
	Control *controls;
	
	Base *first, *second;
public:
	//Constructor
	Player( Base::Corner corner1, Base::Corner corner2,
		Color *color, Control *setting );
	
	//Destructor
	~Player();
	
	//Function that moves the paddles
	void move_paddle();
	
	//function indicating this player is "alive"
	bool is_alive();
	
	//Function for collision detection
	bool ball_collision( Ball *ball );
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif

