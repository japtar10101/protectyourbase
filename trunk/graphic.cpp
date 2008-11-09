/*
class to be extended by almost every objects
in this game
*/
#include "graphic.hpp"

/**** Constructors ****/

Graphic::Graphic() : x( 0.0 ), y( 0.0 ), visible( true ), animated( false ) {}

Graphic::Graphic( float x_coord, float y_coord ) :
x( x_coord ), y( y_coord ), visible( true ), animated( false ) {}

Graphic::Graphic( float x_coord, float y_coord,
	bool is_visible, bool is_animated ) :
x( x_coord ), y( y_coord ), visible( is_visible ),
	animated( is_animated ) {}

/**** Getter and setter for x ****/

void Graphic::set_x( float x_coord ) {
	x = x_coord;
}

float Graphic::get_x() {
	return x;
}

/**** Getter and setter for y ****/

void Graphic::set_y( float y_coord ) {
	y = y_coord;
}

float Graphic::get_y() {
	return y;
}

/**** Getter and setter for visible ****/

void Graphic::set_visible( bool is_visible ) {
	visible = is_visible;
}

bool Graphic::get_visible() {
	return visible;
}

/**** Getter and setter for animated ****/

void Graphic::set_animated( bool is_animated ) {
	animated = is_animated;
}

bool Graphic::get_animated() {
	return animated;
}

/**** Intuitive setter for visible ****/

void Graphic::show() {
	visible = true;
}

void Graphic::hide() {
	visible = false;
}

/**** Intuitive setter for animated ****/

void Graphic::play_animation() {
	animated = true;
}

void Graphic::stop_animation() {
	animated = false;
}

/**** and the rest of the virtual functions ****/

void Graphic::draw() {
	if( visible )
		force_draw();
}

void Graphic::animate() {
	if( animated )
		force_animate();
}

