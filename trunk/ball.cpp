#include "ball.h"

/**** Constructor ****/

Ball::Ball( float radius_val, float x_coord, float y_coord, float velocity ) :
Graphic( x_coord, y_coord, true, true ),
radius( radius_val ),
color( 1.0, 1.0, 1.0 ) {
	//same operation as the default constructor
	float random = 0.0;
	while( random < 0.1 || random > 0.9 ) {
		random = ( (float) rand() ) / ( (float) RAND_MAX + 1.0 );
	}
	
	x_vel = random * velocity;
	if( rand() % 2 ) x_vel *= -1.0;
	
	y_vel = (float) sqrt( pow( velocity, 2.0 ) - pow( x_vel, 2.0 ) );
	if( rand() % 2 ) y_vel *= -1.0;
}

/**** Increase velocity function ****/

void Ball::increase_velocity() {
	float initial_velocity = velocity();
	if( initial_velocity < maximum_velocity ) {
		float increment =
			( initial_velocity + increment_velocity ) / initial_velocity;
		x_vel *= increment;
		y_vel *= increment;
	}
}

/**** some functions that apparently should stay in the cpp file ****/
float Ball::get_x_vel() { return x_vel; }

float Ball::get_y_vel() { return y_vel; }

void Ball::bounce_vertically() {
	//reverse y direction
	y_vel *= -1.0;
	
	//shift the x_velocity a bit
	shift_velocity( true );
}

void Ball::bounce_horizontally() {
	x_vel *= -1.0;
	
	//shift the y_velocity a bit
	shift_velocity( false );
}

/**** override functions ****/

void Ball::force_draw() {
	color.color();
	glBegin( GL_POLYGON );
	for( int index = 0; index < 360; index += 20 ) {
		//draw a circle
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

void Ball::shift_velocity( bool shift_x_vel ) {
	//get the current velocity
	const float cur_vel = velocity();
	
	//get a random variable
	float random = (float) ( rand() % 5 );
	if( rand() % 2 ) random *= -1.0;
	random /= 10000;
	
	if( shift_x_vel ) {
		//shift the x velocity
		x_vel += random;
		
		//is y velocity negative?
		const bool y_neg = y_vel < 0;
		
		//recalculate y velocity
		y_vel = (float) sqrt( cur_vel * cur_vel - x_vel * x_vel );
		
		//and finally make velocity negative
		if( y_neg ) y_vel *= -1.0;
	} else {
		//shift the y velocity
		y_vel += random;
		
		//is x velocity negative?
		const bool x_neg = x_vel < 0;
		
		//recalculate x velocity
		x_vel = (float) sqrt( cur_vel * cur_vel - y_vel * y_vel );
		
		//and finally make velocity negative
		if( x_neg ) x_vel *= -1.0;
	}
	/*
	DEBUG_VAR( "x_vel is %e", x_vel );
	DEBUG_VAR( "y_vel is %e", y_vel );
	*/
}
