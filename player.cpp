#include "player.h"

/**** Contructor & Destructor ****/

Player::Player( Corner corner1, Corner corner2,
	float red, float green, float blue ) :
Graphic(), base_color( new Color( red, green, blue ) ) {
	first = new Base( corner1, base_color );
	second = new Base( corner2, base_color );
}

Player::Player( Corner corner1, Corner corner2, Color *color ) :
Graphic(), color( color ), first( corner1, color ), second( corner2, color ) {}

Player::~Player() {
	DESTROY( color );
	DESTROY( first );
	DESTROY( second );
}

/**** move functions ****/

void Player::move_up() {
    first->move_up();
    second->move_up();
}

void Player::move_down() {
    first->move_down();
    second->move_down();
}

void Player::move_right() {
    first->move_right();
    second->move_right();
}

void Player::move_left() {
    first->move_left();
    second->move_left();
}

/**** is player alive? ****/

bool Player::is_alive() {
    return first->is_visible() || second->is_visible();
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
