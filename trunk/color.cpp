#include "color.h"

Color::Color() : r(0.0), g(0.0), b(0.0), o(1.0) {}

Color::Color( float red, float green, float blue ) :
r(red), g(green), b(blue), o(1.0) {
	//make sure all numbers are in range
	if( r > 1.0 )
		r = 1.0;
	else if( r < 0.0 )
		r = 0.0;
	
	if( g > 1.0 )
		g = 1.0;
	else if( g < 0.0 )
		g = 0.0;
	
	if( b > 1.0 )
		b = 1.0;
	else if( b < 0.0 )
		b = 0.0;
}

Color::Color( float red, float green, float blue, float opacity ) :
r(red), g(green), b(blue), o(opacity) {
	//make sure all numbers are in range
	if( r > 1.0 )
		r = 1.0;
	else if( r < 0.0 )
		r = 0.0;
	
	if( g > 1.0 )
		g = 1.0;
	else if( g < 0.0 )
		g = 0.0;
	
	if( b > 1.0 )
		b = 1.0;
	else if( b < 0.0 )
		b = 0.0;
	
	if( o > 1.0 )
		o = 1.0;
	else if( o < 0.0 )
		o = 0.0;
}

bool Color::is_visible() {
	return o == 1.0;
}
