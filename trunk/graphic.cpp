/*
class to be extended by almost every objects
in this game
*/
#include "graphic.h"

/**** Constructors ****/

Graphic::Graphic() : x( 0.0 ), y( 0.0 ), visible( true ), animated( false ) {}

Graphic::Graphic( float x_coord, float y_coord ) :
x( x_coord ), y( y_coord ), visible( true ), animated( false ) {}

Graphic::Graphic( float x_coord, float y_coord,
	bool is_visible, bool is_animated ) :
x( x_coord ), y( y_coord ), visible( is_visible ),
	animated( is_animated ) {}

/**** virtual setters ****/
void Graphic::set_x( float x_coord ) {
	x = x_coord;
}

void Graphic::set_y( float y_coord ) {
	y = y_coord;
}

/**** draw and animate ****/

void Graphic::draw() {
	if( visible )
		force_draw();
}

void Graphic::animate() {
	if( animated && visible )
		force_animate();
}

/**** boundary functions ****/

float Graphic::bottom() {
	return y;
}

float Graphic::left() {
	return x;
}

