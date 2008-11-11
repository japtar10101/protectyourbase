#ifndef BLOCK_H
#define BLOCK_H

#include "graphic.hpp"

class Block : public Graphic {
private:
	static const float default_dimension = 1;

protected:
	float width, height;
	
public:
	//constructor
	Block();
	Block( float x_coord, float y_coord );
	Ball( float x_coord, float y_coord, float set_width, float set_height );
	
	//getters and setters
	void set_width( float set_width );
	void set_height( float set_height );
	float get_width();
	float get_height();
	
	//functions to override
	void force_draw();
	void force_animate();
	float left();
	float right();
	float top();
	float bottom();
};

#endif

