#include "color.h"

Color::Color() : r( 0.0 ), g( 0.0 ), b( 0.0 ) {}

Color::Color( float red, float green, float blue ) :
r( red ), g( green ), b( blue ) {
	//make sure all numbers are in range
	if( r > 1.0 ) r = 1.0;
	else if( r < 0.0 ) r = 0.0;
	
	if( g > 1.0 ) g = 1.0;
	else if( g < 0.0 ) g = 0.0;
	
	if( b > 1.0 ) b = 1.0;
	else if( b < 0.0 ) b = 0.0;
}

/**** Color setters ****/
void Color::set_color( float red, float green, float blue ) {
	if( red > 1.0 ) r = 1.0;
	else if( red < 0.0 ) r = 0.0;
	else r = red;
	
	if( green > 1.0 ) g = 1.0;
	else if( green < 0.0 ) g = 0.0;
	else g = green;
	
	if( blue > 1.0 ) b = 1.0;
	else if( blue < 0.0 ) b = 0.0;
	else b = blue;
}

void Color::set_red( float red ) {
	if( red > 1.0 ) r = 1.0;
	else if( red < 0.0 ) r = 0.0;
	else r = red;
}
void Color::set_green( float green ) {
	if( green > 1.0 ) g = 1.0;
	else if( green < 0.0 ) g = 0.0;
	else g = green;
}
void Color::set_blue( float blue ) {
	if( blue > 1.0 ) b = 1.0;
	else if( blue < 0.0 ) b = 0.0;
	else b = blue;
}

