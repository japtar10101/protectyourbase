#ifndef BALL_H
#define BALL_H

#include "graphic.hpp"

#include <ctime>

class Ball : public Graphic {
private:
	static const float default_radius = 0.4;
	static const float default_velocity = 0.012;
	static const float increment_velocity = 1.05;
	static const float maximum_velocity = 0.3;

protected:
	float radius;
	float x_vel, y_vel;
	
public:
	//constructor
	Ball();
	Ball( float radius_val );
	Ball( float radius_val, float x_coord, float y_coord );
	Ball( float radius_val, float x_coord, float y_coord, float velocity );
	
	//getters and setters
	void set_radius( float new_radius );
	float get_radius();
	float get_x_vel();
	float get_y_vel();
	
	//functions for the ball to bounce
	void bounce_vertically();
	void bounce_horizontally();
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
	float velocity();
};

#endif

