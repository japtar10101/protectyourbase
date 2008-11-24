#ifndef BASE_H
#define BASE_H

#include "destructible_block.h"
#include "paddle.h"

#define NUM_DESTRUCTIBLE_BLOCKS 7

class Base : public Graphic {
private:
	Color *base_color;
	Paddle *horizontal;
	Paddle *vertical;
	DestructibleBlock *base;
	DestructibleBlock *defense[NUM_DESTRUCTIBLE_BLOCKS];
	
public:
	//Corner enumerator
	enum Corner {
		top_right,
		top_left,
		bottom_right,
		bottom_left
	};
	
	//Constructor
	Base( Corner corner, float red, float green, float blue );
	
	//Destructor
	~Base();
	
	//Functions that moves the paddles
	void move_up()		{ vertical->move_up(); }
	void move_down()	{ vertical->move_down(); }
	void move_left()	{ horizontal->move_left(); }
	void move_right()	{ horizontal->move_right(); }
	
	//function indicating this base is "alive"
	bool is_intact() { return visible; };
	
	//Function for collision detection
	bool ball_collision( Ball *ball );
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif

