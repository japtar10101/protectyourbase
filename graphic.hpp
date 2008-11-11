/*
class to be extended by almost every objects
in this game
*/
#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define DEGR_TO_RADIANS ( 3.14159 / 180 );
#define DUMP( variable ) std::cout << "File " << __FILE__ << ", line "\
	<< __LINE__ << ":\n" << #variable " = " << variable << std::endl
#define DEBUG( string ) std::cout << "File " << __FILE__ << ", line "\
	<< __LINE__ << ":\n" << string << std::endl
#define DEBUG_VAR( string, variable ) printf( "File %s, line %d:\n"\
	#string "\n", __FILE__, __LINE__, variable )

class Graphic {
protected:
	float x, y;
	bool visible, animated;
	
public:
	//Constructor
	Graphic();
	Graphic( float x_coord, float y_coord );
	Graphic( float x_coord, float y_coord,
		bool is_visible, bool is_animated );
	
	//getters and setters
	//I made setters for x and y virtual
	virtual void set_x( float x_coord );
	float get_x();
	virtual void set_y( float y_coord );
	float get_y();
	void set_visible( bool is_visible );
	bool get_visible();
	void set_animated( bool is_animated );
	bool get_animated();
	
	//setters with a more intuitive name
	void show();
	void hide();
	void play_animation();
	void stop_animation();
	
	//draw and animate functions
	//they HAVE to be virtual
	virtual void draw();
	virtual void animate();
	virtual void force_draw() = 0;
	virtual void force_animate() = 0;
};

#endif

