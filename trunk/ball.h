#ifndef BALL_H
#define BALL_H

#include "graphic.h"
#include "color.h"

class Ball : public Graphic {
private:
	static const float default_radius = 0.5;
	static const float default_velocity = 0.01;
	static const float increment_velocity = 0.002;
	static const float maximum_velocity = 0.1;
	float radius;
	float x_vel, y_vel;
	Color color;
	
public:
	//constructor
	Ball( float radius_val, float x_coord, float y_coord, float velocity );
	
	//getters and setters
	void set_radius( float new_radius )	{ radius = new_radius; }
	float get_radius()					{ return radius; }
	float get_x_vel();
	float get_y_vel();
	
	//functions for the ball to bounce
	void bounce_vertically()	{ y_vel *= -1.0; }
	void bounce_horizontally()	{ x_vel *= -1.0; }
	void bounce_diagonally();
	
	//increase velocity
	void increase_velocity();
	
	//functions to override
	void force_draw();
	void force_animate();
	float left();
	float right();
	float top();
	float bottom();
	
	//helper functions
	float velocity() { 
		return (float) sqrt( pow( x_vel, 2.0 ) + pow( y_vel, 2.0 ) );
	}
};

#endif

