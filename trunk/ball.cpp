#include "ball.h"

/**** Constructor ****/

Ball::Ball() :
Graphic( 0.0, 0.0, true, true ),
radius( default_radius ),
color( 1.0, 1.0, 1.0 ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random < 0.1 || random > 0.9 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	if( rand() % 2 ) {
		x_vel *= -1.0;
	}
	
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
	if( rand() % 2 ) {
		y_vel *= -1.0;
	}
}

Ball::Ball( float radius_val ) :
Graphic( 0.0, 0.0, true, true ),
radius( radius_val ),
color( 1.0, 1.0, 1.0 ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random < 0.1 || random > 0.9 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	if( rand() % 2 ) {
		x_vel *= -1.0;
	}
	
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
	if( rand() % 2 ) {
		y_vel *= -1.0;
	}
}

Ball::Ball( float radius_val, float x_coord, float y_coord ) :
Graphic( x_coord, y_coord, true, true ),
radius( radius_val ),
color( 1.0, 1.0, 1.0 ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random < 0.1 || random > 0.9 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	
	//give x_vel a random velocity value
	x_vel = random * default_velocity;
	if( rand() % 2 ) {
		x_vel *= -1.0;
	}
	
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( default_velocity, 2.0 ) - pow( x_vel, 2.0 ) );
	if( rand() % 2 ) {
		y_vel *= -1.0;
	}
}

Ball::Ball( float radius_val, float x_coord, float y_coord, float velocity ) :
Graphic( x_coord, y_coord, true, true ),
radius( radius_val ),
color( 1.0, 1.0, 1.0 ) {
	//grab a random value between (but not equal to) 0 and 1
	float random = 0.0;
	while( random < 0.1 || random > 0.9 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	
	//give x_vel a random velocity value
	x_vel = random * velocity;
	if( rand() % 2 ) {
		x_vel *= -1.0;
	}
	
	//calculate the y_vel corresponding to x_vel and default_velocity
	//note: x_vel has to be less than default_velocity
	y_vel = (float) sqrt( pow( velocity, 2.0 ) - pow( x_vel, 2.0 ) );
	if( rand() % 2 ) {
		y_vel *= -1.0;
	}
}

/**** Increase velocity function ****/

void Ball::increase_velocity() {
	if( velocity() < maximum_velocity ) {
		x_vel *= increment_velocity;
		y_vel *= increment_velocity;
	}
}

/**** some functions that apparently should stay in the cpp file ****/
float Ball::get_x_vel() { return x_vel; }

float Ball::get_y_vel() { return y_vel; }

void Ball::bounce_diagonally() {
	x_vel *= -1.0;
	y_vel *= -1.0;
}

/**** override functions ****/

void Ball::force_draw() {
	color.color();
	glBegin( GL_POLYGON );
	for( int index = 0; index < 360; index += 20 ) {
		float degInRad = index * DEGR_TO_RADIANS;
		float x_coord = cos( degInRad );
		x_coord = x_coord * radius + x;
		float y_coord = sin( degInRad );
		y_coord = y_coord * radius + y;
		glVertex2f( x_coord, y_coord );
	}
	glEnd();
}

void Ball::force_animate() {
	x += x_vel;
	y += y_vel;
}

float Ball::left() {
	return x - radius;
}

float Ball::right() {
	return x + radius;
}

float Ball::top() {
	return y + radius;
}

float Ball::bottom() {
	return y - radius;
}

