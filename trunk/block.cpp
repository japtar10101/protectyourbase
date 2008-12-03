#include "block.h"

/**** Constructor ****/

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
	glBegin( GL_QUADS );
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
bool Block::ball_collision( Ball *ball ) {
	//if the block is not visible, do nothing
	if( !visible ) return false;
	else {
		//grab all the variables
		const float block_top = top(), block_bottom = bottom(),
			block_right = right(), block_left = left(),
			ball_top = ball->top(), ball_bottom = ball->bottom(),
			ball_left = ball->left(), ball_right = ball->right();
		
		//Condition for the ball hitting the block
		if( ball_left < block_right && ball_right > block_left &&
			ball_bottom < block_top && ball_top > block_bottom ) {
			//Collision detection, v4.0
			
			//ball position calculation and velocity calculation
			const float ball_x = ball->get_x(), ball_y = ball->get_y(),
				x_velocity = ball->get_x_vel(), y_velocity = ball->get_y_vel();
			
			//boolean calculation on which side the ball hit
			const bool hit_top = ball_y > block_top,
				hit_bottom = ball_y < block_bottom,
				hit_right = ball_x > block_right,
				hit_left = ball_x < block_left;
			
			//if the ball was moving downwards, and hits the top of the block,
			//bounce. Vice versa for ball moving upwards
			if( ( hit_top && y_velocity < 0.0 ) ||
				( hit_bottom && y_velocity > 0.0 ) )
					ball->bounce_vertically();
			
			//if the ball was moving right, and hits the left side of the block,
			//bounce. Vice versa for ball moving upwards
			if( ( hit_right && x_velocity < 0.0 ) ||
				( hit_left && x_velocity > 0.0 ) )
					ball->bounce_horizontally();
			return true;
		} else return false;
	}
}

bool Block::mouse_over( Mouse *controls ) {
	const float mouse_x = controls->get_x(), mouse_y = controls->get_y();
	return ( mouse_y > bottom() && mouse_y < top() ) &&
		( mouse_x > left() && mouse_x < right() );
}

