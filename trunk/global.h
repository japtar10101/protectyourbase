#ifndef GLOBAL_H
#define GLOBAL_H

#include <GL/glut.h>

/**** Debugging macros ****/

#define DEGR_TO_RADIANS ( 3.14159 / 180 );

#define DEBUG( string ) printf( "File %s, line %d: %s\n", \
	__FILE__, __LINE__, string )

#define DEBUG_VAR( string, variable ) printf( "File %s, line %d: "\
	#string "\n", __FILE__, __LINE__, variable )

/**** "sane" pointer destructor ****/

#define DESTROY( pointer ) if( pointer ) {\
	delete pointer;\
	pointer = NULL;\
}

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

#endif

