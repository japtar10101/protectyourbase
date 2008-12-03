#ifndef GLOBAL_H
#define GLOBAL_H

#include <GL/glut.h>
#include <stdio.h>

/**** Debugging macros ****/

#define DEGR_TO_RADIANS ( 3.14159 / 180 )

#define NUM_COLORS 6

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

static const int window_position_x = 200, window_position_y = 50,
	window_size_width = 700, window_size_height = 700;

static const GLdouble grid_width = 30.0, grid_height = 30.0;

/**** Elements traits ****/

static const float
	ball_radius = 0.5,
	beginning_velocity = 0.012;

static const unsigned char 
	player_one_controls[8] = { 'w', 'W', 's', 'S', 'a', 'A', 'd', 'D' },
	player_two_controls[8] = { 'p', 'P', ';', ':', 'l', 'L', '\'', '"' };

static const float all_colors[NUM_COLORS][3] = {
	{ 1.0, 0.0, 0.0 }	//red
	, { 1.0, 0.5, 0.0 }	//orange
	, { 1.0, 1.0, 0.0 }	//yellow
	, { 0.0, 0.7, 0.0 }	//green
	, { 0.0, 0.0, 1.0 }	//blue
	, { 0.7, 0.0, 0.7 }	//violet
};
#endif

