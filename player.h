#ifndef PLAYER_H
#define PLAYER_H

#include "base.h"

class Player : public Graphic {
private:
	Base *first, *second;
	Color *base_color;
public:
	//Constructor
	Player( Base::Corner corner1, Base::Corner corner2, Color *color );
	
	//Destructor
	~Player();
	
	//Functions that moves the paddles
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	
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

