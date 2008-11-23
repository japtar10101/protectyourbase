#include "block.h"

/**** Constructor ****/

Block::Block() : Graphic(), width( 1.0 ), height( 1.0 ) {}

Block::Block( float x_coord, float y_coord ) :
Graphic( x_coord, y_coord ), width( 1.0 ), height( 1.0 ) {}

Block::Block( float x_coord, float y_coord, float set_width, float set_height )
: Graphic( x_coord, y_coord ), width( set_width ), height( set_height ) {}

/**** Getters and setters ****/

void Block::set_width( float set_width ) {
	width = set_width;
}

void Block::set_height( float set_height ) {
	height = set_height;
}

float Block::get_width() {
	return width;
}

float Block::get_height() {
	return height;
}

/**** functions to override ****/

void Block::force_draw() {
	glBegin( GL_POLYGON );
		glVertex2f( x, y );
		glVertex2f( x, y + height );
		glVertex2f( x + width, y + height );
		glVertex2f( x + width, y );
	glEnd();
}

void Block::force_animate() {
	//nothing special
	animated = false;
}

float Block::right() {
	return x + width;
}

float Block::top() {
	return y + height;
}

/**** collision detection ****/
bool Block::ball_collision( Ball &ball ) {
	//if the block is not visible, do nothing
	if( !visible ) return false;
	//grab all the variables
	const float block_top = top(), block_bottom = bottom(),
		block_right = right(), block_left = left(),
		ball_top = ball.top(), ball_bottom = ball.bottom(),
		ball_left = ball.left(), ball_right = ball.right();
	bool to_return = false;
	//Condition for the ball hitting the block
	if( ball_left < block_right && ball_right > block_left &&
		ball_bottom < block_top && ball_top > block_bottom ) {
	//lots of calculations
		const float ball_x = ball.get_x(), ball_y = ball.get_y(),
			x_velocity = ball.get_x_vel(), y_velocity = ball.get_y_vel();
		const bool hit_top = ball_y > block_top,
			hit_bottom = ball_y < block_bottom,
			hit_right = ball_x > block_right,
			hit_left = ball_x < block_left;
		//Condition for hitting the corners
		if( ( hit_top && hit_right && x_velocity < 0.0 && y_velocity < 0.0 ) ||
			( hit_bottom && hit_right && x_velocity < 0.0 && y_velocity > 0.0 ) ||
			( hit_top && hit_left && x_velocity > 0.0 && y_velocity < 0.0 ) ||
			( hit_bottom && hit_left && x_velocity > 0.0 && y_velocity > 0.0 ) ) {
			ball.bounce_diagonally();
		//Condition the ball hit the top or bottom
		} else if( hit_top || hit_bottom ) {
			ball.bounce_vertically();
		//Condition the ball hit the left or right
		} else if( hit_right || hit_left ) {
			ball.bounce_horizontally();
		}
		to_return = true;
	}
	return to_return;
}

