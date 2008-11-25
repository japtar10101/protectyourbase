#ifndef BLOCK_H
#define BLOCK_H

#include "graphic.h"
#include "ball.h"

class Block : public Graphic {
private:
	static const float default_dimension = 1;

protected:
	float width, height;
	
public:
	//constructor
	Block( float x_coord, float y_coord, float set_width, float set_height );
	
	//getters and setters
	void set_width( float set_width );
	void set_height( float set_height );
	float get_width();
	float get_height();
	
	//functions to override
	virtual void force_draw();
	virtual void force_animate();
	float right();
	float top();
	
	//collision detection
	virtual bool ball_collision( Ball *ball );
};

#endif

