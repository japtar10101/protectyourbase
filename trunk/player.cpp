#include "player.h"

/**** Contructor & Destructor ****/

Player::Player( Base::Corner corner1, Base::Corner corner2, Color *color,
	Control *setting, Color *level1, Color *level2, Color *level3 ) :
Graphic(),
first( new Base( corner1, color, setting, level1, level2, level3 ) ),
second( new Base( corner2, color, setting, level1, level2, level3 ) ) {}

Player::~Player() {
	DESTROY( first );
	DESTROY( second );
}

/**** move functions ****/

void Player::move_paddle() {
   first->move_paddle();
   second->move_paddle();
}

/**** is player alive? ****/

bool Player::is_alive() {
	return first->get_visible() || second->get_visible();
}

/**** collision detection ****/

bool Player::ball_collision( Ball *ball ) {
	animated = first->ball_collision( ball );
	animated = second->ball_collision( ball ) || animated;
	return animated;
}

/**** override ****/

void Player::force_draw() {
	first->draw();
	second->draw();
}

void Player::force_animate() {
	first->animate();
	second->animate();
	stop_animation();
}

float Player::top() {
	float first_top = first->top(), second_top = second->top();
	return ( first_top > second_top ? first_top : second_top );
}

float Player::right() {
	float first_right = first->right(), second_right = second->right();
	return ( first_right > second_right ? first_right : second_right );
}
