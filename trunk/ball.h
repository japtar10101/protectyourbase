#ifndef BALL_H
#define BALL_H

#include "graphic.h"
#include "color.h"

class Ball : public Graphic {
private:
	static const float
		increment_velocity = 0.002
		, maximum_velocity = 0.1
		, shift_constant = 0.001;
	float radius;
	float x_vel, y_vel;
	Color color;
	
	//helper functions
	float velocity() { 
		return (float) sqrt( pow( x_vel, 2.0 ) + pow( y_vel, 2.0 ) );
	}
	void shift_velocity( bool shift_x_vel );
public:
	//constructor
	Ball( float radius_val, float x_coord, float y_coord, float velocity );
	
	//getters and setters
	void set_radius( float new_radius )	{ radius = new_radius; }
	float get_radius()					{ return radius; }
	float get_x_vel();
	float get_y_vel();
	
	//functions for the ball to bounce
	void bounce_vertically();
	void bounce_horizontally();
	
	//increase velocity
	void increase_velocity();
	
	//functions to override
	void force_draw();
	void force_animate();
	float left();
	float right();
	float top();
	float bottom();
};

#endif

