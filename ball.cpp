#include "ball.hpp"

/**** Constructor ****/

Ball::Ball() :
Graphic( 0.0, 0.0, true, true ), radius( default_radius ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random == 0.0 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
}

Ball::Ball( float radius_val ) :
Graphic( 0.0, 0.0, true, true ), radius( radius ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random == 0.0 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
}

Ball::Ball( float radius_val, float x_coord, float y_coord ) :
Graphic( x_coord, y_coord, true, true ), radius( radius ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random == 0.0 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
}

Ball::Ball( float radius_val, float x_coord, float y_coord, float velocity ) :
Graphic( x_coord, y_coord, true, true ), radius( radius ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random == 0.0 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	//give x_vel a random velocity value
	x_vel = random * velocity;
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( velocity, 2.0 ) - pow( x_vel, 2.0 ) );
}

/**** getter and setter ****/

void Ball::set_radius( float new_radius ) {
	radius = new_radius;
}

float Ball::get_radius() {
	return radius;
}

float Ball::get_x_vel() {
	return x_vel;
}

float Ball::get_y_vel() {
	return y_vel;
}

/**** override functions ****/

void Ball::force_draw() {
	glColor3f( 1.0, 1.0, 1.0 );
	glBegin( GL_POLYGON );
	for( int index = 0; index < 360; index += 2 ) {
		float degInRad = index * DEGR_TO_RADIANS;
		float x_coord = cos( degInRad );
		x_coord = x_coord * radius + Graphic::x;
		float y_coord = sin( degInRad );
		y_coord = y_coord * radius + Graphic::y;
		glVertex2f( x_coord, y_coord );
	}
	glEnd();
}

void Ball::force_animate() {
	Graphic::x += x_vel;
	Graphic::y += y_vel;
}

/**** Bounce functions ****/

void Ball::bounce_vertically() {
	y_vel *= (-1.0);
}

void Ball::bounce_horizontally() {
	x_vel *= (-1.0);
}

void Ball::bounce_diagonally() {
	x_vel *= (-1.0);
	y_vel *= (-1.0);
}

/**** Increase velocity function ****/

void Ball::increase_velocity() {
	x_vel *= increment_velocity;
	y_vel *= increment_velocity;
}

