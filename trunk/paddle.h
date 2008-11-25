#ifndef PADDLE_H
#define PADDLE_H

#include "block.h"
#include "color.h"

class Paddle : public Block {
private:
	static const float velocity = 0.4;
	static const float default_range = 10.0;
	Color *color;
	//limits: the range the paddle can move
	float upper_limit, lower_limit;
	//vertical: if true, moves horizontal; false, vertical
	bool horizontal;
	
public:
	//constructor & destructor
	Paddle( float x_coord, float y_coord, float set_width, float set_height,
		float range_of_movement, bool move_horizontal, Color *paddle_color );
	~Paddle();
	
	//getter and setter
	bool get_horizontal()	{ return horizontal; }
	float get_upper_limit()		{ return upper_limit; }
	float get_lower_limit()		{ return lower_limit; }
	Color *get_color();
	void set_horizontal( bool change ) { horizontal = change; }
	void set_upper_limit( float limit );
	void set_lower_limit( float limit );
	void set_limit( float lower, float upper );
	
	//more intuitive getters
	bool moves_horizontally()	{ return horizontal; }
	bool moves_vertically()		{ return !horizontal; }
	
	//functions that moves the paddle
	void move_up();
	void move_down();
	void move_right();
	void move_left();
	
	//override function
	void force_animate();
	void force_draw();
	bool ball_collision( Ball *ball );
};

#endif

