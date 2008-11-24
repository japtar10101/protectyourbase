#include "base.h"

/**** Contructor & Destructor ****/

Base::Base( Corner corner, float red, float green, float blue ) :
base_color( new Color( red, green, blue ) ) {
	//variables used commonly in all arguements
	int index = 0;
	Color *level1 = new Color( 1.0, 0.0, 0.0 );
	Color *level2 = new Color( 1.0, 5.0, 0.0 );
	Color *level3 = new Color( 1.0, 1.0, 0.0 );
	
	//Different shapes for each corner
	switch( corner ) {
		case top_right:
			//set the graphic variables
			x = grid_width - 10.0;
			y = grid_height - 10.0;
			
			//make the base
			base = new DestructibleBlock( x + 4.0, y + 4.0, 6.0, 6.0, base_color );
			
			//make the paddles
			horizontal = new Paddle( x + 1.0, y, 3.0, 1.0, 6.0, true, base_color );
			vertical = new Paddle( x, y + 1.0, 1.0, 3.0, 6.0, false, base_color );
			
			//make defense blocks
			//corner
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 1.0, 3.0, 3.0, level2 );
			
			//bottom side
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 1.0, 6.0, 1.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 2.0, 6.0, 1.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 3.0, 6.0, 1.0, level1 );
			
			//left side
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 4.0, 1.0, 6.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 2.0, y + 4.0, 1.0, 6.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 3.0, y + 4.0, 1.0, 6.0, level1 );
			break;
			
		case top_left:
			//same pattern as above
			x = 0.0;
			y = grid_height - 10.0;
			base = new DestructibleBlock( x, y + 4.0, 6.0, 6.0, base_color );
			horizontal = new Paddle( x, y, 3.0, 1.0, 6.0, true, base_color );
			vertical = new Paddle( x + 9.0, y + 1.0, 1.0, 3.0, 6.0, false, base_color );
			//corner
			defense[index++] = new DestructibleBlock(
				x + 6.0, y + 1.0, 3.0, 3.0, level2 );
			//bottom side
			defense[index++] = new DestructibleBlock(
				x, y + 1.0, 6.0, 1.0, level3 );
			defense[index++] = new DestructibleBlock(
				x, y + 2.0, 6.0, 1.0, level2 );
			defense[index++] = new DestructibleBlock(
				x, y + 3.0, 6.0, 1.0, level1 );
			//right side
			defense[index++] = new DestructibleBlock(
				x + 8.0, y + 4.0, 1.0, 6.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 7.0, y + 4.0, 1.0, 6.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 6.0, y + 4.0, 1.0, 6.0, level1 );
			break;
			
		case bottom_right:
			x = grid_width - 10.0;
			y = 0.0;
			//FIXME: finish this condition
			base = new DestructibleBlock( x + 4.0, y + 4.0, 6.0, 6.0, base_color );
			horizontal = new Paddle( x + 1.0, y, 3.0, 1.0, 6.0, true, base_color );
			vertical = new Paddle( x, y + 1.0, 1.0, 3.0, 6.0, false, base_color );
			//corner
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 1.0, 3.0, 3.0, level2 );
			//bottom side
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 1.0, 6.0, 1.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 2.0, 6.0, 1.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 3.0, 6.0, 1.0, level1 );
			//left side
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 4.0, 1.0, 6.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 2.0, y + 4.0, 1.0, 6.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 3.0, y + 4.0, 1.0, 6.0, level1 );
			break;
			
		case bottom_left:
		default:
			x = 0.0;
			y = 0.0;
			//FIXME: finish this condition
			base = new DestructibleBlock( x + 4.0, y + 4.0, 6.0, 6.0, base_color );
			horizontal = new Paddle( x + 1.0, y, 3.0, 1.0, 6.0, true, base_color );
			vertical = new Paddle( x, y + 1.0, 1.0, 3.0, 6.0, false, base_color );
			//corner
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 1.0, 3.0, 3.0, level2 );
			//bottom side
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 1.0, 6.0, 1.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 2.0, 6.0, 1.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 4.0, y + 3.0, 6.0, 1.0, level1 );
			//left side
			defense[index++] = new DestructibleBlock(
				x + 1.0, y + 4.0, 1.0, 6.0, level3 );
			defense[index++] = new DestructibleBlock(
				x + 2.0, y + 4.0, 1.0, 6.0, level2 );
			defense[index++] = new DestructibleBlock(
				x + 3.0, y + 4.0, 1.0, 6.0, level1 );
	}
}

Base::~Base() {
	delete base_color;
	base_color = NULL;
	delete horizontal;
	delete vertical;
	delete base;
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
		delete defense[index];
	}
}

/**** Function for collision detection ****/

bool Base::ball_collision( Ball *ball ) {
	bool collide = false;
	if( base->ball_collision( ball ) ) {
		base->play_animation();
		horizontal->play_animation();
		vertical->play_animation();
		for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
			defense[index]->play_animation();
		}
		play_animation();
	} else {
		collide = horizontal->ball_collision( ball );
		collide = vertical->ball_collision( ball ) || collide;
		for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
			collide = defense[index]->ball_collision( ball ) || collide;
		}
	}
	return collide;
}

/**** Functions that has to be overridden ****/

void Base::force_draw() {
	horizontal->draw();
	vertical->draw();
	base->draw();
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
		defense[index]->draw();
	}
}

void Base::force_animate() {
	horizontal->animate();
	vertical->animate();
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
		defense[index]->animate();
	}
	if( animated ) {
		base->animate();
		hide();
	}
}

float Base::top() {
	return y + 10.0;
}

float Base::right() {
	return x + 10.0;
}

