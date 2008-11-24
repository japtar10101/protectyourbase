#ifndef GLOBAL_H
#define GLOBAL_H

#include <GL/glut.h>

/**** Debugging macros ****/

#define DEGR_TO_RADIANS ( 3.14159 / 180 );

#define DUMP( variable ) std::cout << "File " << __FILE__ << ", line "\
	<< __LINE__ << ":\n" << #variable " = " << variable << std::endl

#define DEBUG( string ) printf( "File %s, line %d: %s\n", \
	__FILE__, __LINE__, string )

#define DEBUG_VAR( string, variable ) printf( "File %s, line %d: "\
	#string "\n", __FILE__, __LINE__, variable )

/**** Window traits ****/

static const int
	window_size_width = 700
	, window_size_height = 700
	, window_position_x = 0
	, window_position_y = 0;

static const GLdouble
	grid_width = 30.0
	, grid_height = 30.0;

static const float
	ball_radius = 0.5,
	beginning_velocity = 0.012;

static const unsigned char
	control_up[4] = { 'w', 'W', 'p', 'P' }
	, control_down[4] = { 's', 'S', ';', ':' }
	, control_left[4] = { 'a', 'A', 'l', 'L' }
	, control_right[4] = { 'd', 'D', '\'', '"' };

#endif

