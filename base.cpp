#include "base.h"

/**** Contructor & Destructor ****/

Base::Base( Corner corner, Color *color, Control *setting,
	Color *block1, Color *block2, Color *block3 ) :
Graphic(), base_color( color ), level1( block1 ),
level2( block2 ), level3( block3 ), controls( setting ),
//set everything to null
horizontal( NULL ), vertical( NULL ), base( NULL ) {
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index )
		defense[index] = NULL;
	
	//Different shapes for each corner
	switch( corner ) {
		case top_right:
			generate_top_right_corner( level1, level2, level3 );
			break;
		case top_left:
			generate_top_left_corner( level1, level2, level3 );
			break;
		case bottom_right:
			generate_bottom_right_corner( level1, level2, level3 );
			break;
		case bottom_left:
		default:
			generate_bottom_left_corner( level1, level2, level3 );
	}
}

Base::~Base() {
	/* Base does not own color or controls
	DESTROY( base_color );
	DESTROY( controls );
	*/
	destroy_all();
}

/**** helper generator functions ****/
void Base::destroy_all() {
	DESTROY( horizontal );
	DESTROY( vertical );
	DESTROY( base );
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index )
		DESTROY( defense[index] );
}

void Base::generate_top_right_corner( Color *level1, Color *level2, Color *level3 ) {
	//set the graphic variables
	destroy_all();
	int index = 0;
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
}

void Base::generate_top_left_corner( Color *level1, Color *level2, Color *level3 ) {
	//same pattern as above
	destroy_all();
	int index = 0;
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
}

void Base::generate_bottom_right_corner( Color *level1, Color *level2, Color *level3 ) {
	destroy_all();
	int index = 0;
	x = grid_width - 10.0;
	y = 0.0;
	base = new DestructibleBlock( x + 4.0, y, 6.0, 6.0, base_color );
	horizontal = new Paddle( x + 1.0, y + 9.0, 3.0, 1.0, 6.0, true, base_color );
	vertical = new Paddle( x, y, 1.0, 3.0, 6.0, false, base_color );
	//corner
	defense[index++] = new DestructibleBlock(
		x + 1.0, y + 6.0, 3.0, 3.0, level2 );
	//top side
	defense[index++] = new DestructibleBlock(
		x + 4.0, y + 6.0, 6.0, 1.0, level3 );
	defense[index++] = new DestructibleBlock(
		x + 4.0, y + 7.0, 6.0, 1.0, level2 );
	defense[index++] = new DestructibleBlock(
		x + 4.0, y + 8.0, 6.0, 1.0, level1 );
	//left side
	defense[index++] = new DestructibleBlock(
		x + 1.0, y, 1.0, 6.0, level3 );
	defense[index++] = new DestructibleBlock(
		x + 2.0, y, 1.0, 6.0, level2 );
	defense[index++] = new DestructibleBlock(
		x + 3.0, y, 1.0, 6.0, level1 );
}

void Base::generate_bottom_left_corner( Color *level1, Color *level2, Color *level3 ) {
	destroy_all();
	int index = 0;
	x = 0.0;
	y = 0.0;
	base = new DestructibleBlock( x, y, 6.0, 6.0, base_color );
	horizontal = new Paddle( x, y + 9.0, 3.0, 1.0, 6.0, true, base_color );
	vertical = new Paddle( x + 9.0, y, 1.0, 3.0, 6.0, false, base_color );
	//corner
	defense[index++] = new DestructibleBlock(
		x + 6.0, y + 6.0, 3.0, 3.0, level2 );
	//top side
	defense[index++] = new DestructibleBlock(
		x, y + 8.0, 6.0, 1.0, level3 );
	defense[index++] = new DestructibleBlock(
		x, y + 7.0, 6.0, 1.0, level2 );
	defense[index++] = new DestructibleBlock(
		x, y + 6.0, 6.0, 1.0, level1 );
	//right side
	defense[index++] = new DestructibleBlock(
		x + 8.0, y, 1.0, 6.0, level3 );
	defense[index++] = new DestructibleBlock(
		x + 7.0, y, 1.0, 6.0, level2 );
	defense[index++] = new DestructibleBlock(
		x + 6.0, y, 1.0, 6.0, level1 );
}

/*** Function that moves the paddles ****/
void Base::move_paddle() {
	//move paddles based on controls
	if( controls->get_key_condition( Control::up ) )
		vertical->move_up();
	if( controls->get_key_condition( Control::down ) )
		vertical->move_down();
	if( controls->get_key_condition( Control::left ) )
		horizontal->move_left();
	if( controls->get_key_condition( Control::right ) )
		horizontal->move_right();
}

/**** Function for collision detection ****/

bool Base::ball_collision( Ball *ball ) {
	animated = base->ball_collision( ball );
	if( animated ) {
		//base hit, destroy everything
		base->play_animation();
		horizontal->play_animation();
		vertical->play_animation();
		for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index ) {
			defense[index]->play_animation();
		}
		play_animation();
	} else {
		//else, check everything if they're hit
		animated = horizontal->ball_collision( ball );
		animated = vertical->ball_collision( ball ) || animated;
		for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index )
			animated = defense[index]->ball_collision( ball ) || animated;
	}
	return animated;
}

/**** Functions that has to be overridden ****/

void Base::force_draw() {
	horizontal->draw();
	vertical->draw();
	base->draw();
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index )
		defense[index]->draw();
}

void Base::force_animate() {
	horizontal->animate();
	vertical->animate();
	for( int index = 0; index < NUM_DESTRUCTIBLE_BLOCKS; ++index )
		defense[index]->animate();
	if( base->get_animated() ) {
		base->animate();
		hide();
	}
	stop_animation();
}

float Base::top() {
	return y + 10.0;
}

float Base::right() {
	return x + 10.0;
}

