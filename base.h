#ifndef BASE_H
#define BASE_H

#include "destructible_block.h"
#include "paddle.h"
#include "control.h"

#define NUM_DESTRUCTIBLE_BLOCKS 13

class Base : public Graphic {
public:
//Corner enumerator
enum Corner { top_right, top_left, bottom_right, bottom_left };

private:
	//member variables
	Corner position;
	Color *base_color, *level1, *level2, *level3;
	Control *controls;
	
	Paddle *horizontal;
	Paddle *vertical;
	
	DestructibleBlock *base;
	DestructibleBlock *defense[NUM_DESTRUCTIBLE_BLOCKS];
	
	//helper generator functions
	void destroy_all();
	void generate_top_right_corner(
		Color *level1,Color *level2, Color *level3 );
	void generate_top_left_corner(
		Color *level1, Color *level2, Color *level3 );
	void generate_bottom_right_corner(
		Color *level1, Color *level2, Color *level3 );
	void generate_bottom_left_corner(
		Color *level1, Color *level2, Color *level3 );
public:
	//Constructor
	Base( Corner corner, Color *color, Control *setting,
		Color *block1, Color *block2, Color *block3 );
	
	//Destructor
	~Base();
	
	//Function that moves the paddles
	void move_paddle();
	
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

