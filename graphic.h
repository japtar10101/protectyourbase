#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "global.h"

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
	float get_x() 		{ return x; }
	float get_y()		{ return y; }
	bool get_visible()	{ return visible; }
	bool get_animated()	{ return animated; }
	virtual void set_x( float x_coord );
	virtual void set_y( float y_coord );
	void set_visible( bool is_visible )   { visible = is_visible; }
	void set_animated( bool is_animated ) { animated = is_animated; }
	
	//setters with a more intuitive name
	void show() 			{ visible = true; }
	void hide()				{ visible = false; }
	void play_animation()	{ animated = true; }
	void stop_animation()	{ animated = false; }
	
	//draw and animate functions
	//they HAVE to be virtual
	virtual void draw();
	virtual void animate();
	virtual void force_draw() = 0;
	virtual void force_animate() = 0;
	
	//boundary functions
	virtual float bottom();
	virtual float left();
	virtual float top() = 0;
	virtual float right() = 0;
};

#endif

