#include "mouse.h"

/**** MouseControls functions ****/

/**** Constructor ****/

MouseControl::MouseControl( int button, int up_down, int x_pos, int y_pos ) :
x( x_pos ), y( y_pos ), btn( button ), ud( up_down ) {}

/**** Setter ****/

void MouseControl::change_state(
	int button, int up_down, int x_pos, int y_pos ) {
	btn = button;
	ud = up_down;
	x = x_pos;
	y = y_pos;
}

/**** enum functions ****/

MouseControl::Button MouseControl::button() {
	if( btn == GLUT_LEFT_BUTTON )		return left;
	else if( btn == GLUT_MIDDLE_BUTTON )return middle;
	else if( btn == GLUT_RIGHT_BUTTON)	return right;
	else								return none;
}

MouseControl::State MouseControl::state() {
	if( ud == GLUT_DOWN )	return down;
	else					return up;
}

/**** Mouse functions ****/

Mouse::Mouse() : control( GLUT_LEFT_BUTTON, GLUT_UP, 0, 0 ) {}

MouseControl::Button Mouse::get_button() {
	if( control.state() == MouseControl::down )
		return control.button();
	else return MouseControl::none;
}

float Mouse::get_x() {
	//if out of window bounds, return a negative value
	if( control.x > window_size_width || control.x < window_position_x )
		return OUT_OF_BOUNDS;
	//calculate based on the global variables
	float x_pos = (float) control.x;
	const float convert =
		( (float) grid_height ) / ( (float) window_size_width );
	return x_pos * convert;
}

float Mouse::get_y() {
	//if out of window bounds, return a negative value
	if( control.y > window_size_height || control.y < window_position_y )
		return OUT_OF_BOUNDS;
	//calculate based on the global variables
	float y_pos = (float) ( window_size_height - control.y );
	const float convert =
		( (float) grid_height ) / ( (float) window_size_width );
	return y_pos * convert;
}
