#ifndef DESTRUCTIBLE_BLOCK_H
#define DESTRUCTIBLE_BLOCK_H

#include "block.h"
#include "color.h"

class DestructibleBlock : public Block {
private:
	Color color;
	
public:
	//constructor
	DestructibleBlock();
	DestructibleBlock( float red, float green, float blue );
	DestructibleBlock( float x_coord, float y_coord );
	DestructibleBlock( float x_coord, float y_coord,
		float red, float green, float blue );
	DestructibleBlock( float x_coord, float y_coord,
		float set_width, float set_height );
	DestructibleBlock( float x_coord, float y_coord,
		float set_width, float set_height,
		float red, float green, float blue );
	
	//getter
	Color &get_color();
	
	//override function
	void force_draw();
	void force_animate();
	bool ball_collision( Ball &ball );
};

#endif

