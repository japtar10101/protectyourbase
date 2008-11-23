#ifndef COLOR_H
#define COLOR_H

#include <GL/glut.h>

class Color {
	/*
	variables:
	red, green, blue
	*/
	float r, g, b;
	
public:
	/*
	Constructor:
	default color is black
	*/
	Color();
	Color( float red, float green, float blue );
	
	//setters and getters
	void set_color( float red, float green, float blue );
	void set_red( float red );
	void set_green( float green );
	void set_blue( float blue );
	float get_red() { return r; }
	float get_green() { return g; }
	float get_blue() { return b; }
	
	//sets the color using glColor3f
	void color() { glColor3f( r, g, b ); }
};

#endif

