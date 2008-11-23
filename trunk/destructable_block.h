#ifndef DESTRUCTABLE_BLOCK_H
#define DESTRUCTABLE_BLOCK_H

#include "block.h"
#include "color.h"

class DestructableBlock : public Block {
private:
	Color color;
	
public:
	//constructor
	DestructableBlock();
	DestructableBlock( float red, float green, float blue );
	DestructableBlock( float x_coord, float y_coord );
	DestructableBlock( float x_coord, float y_coord,
		float red, float green, float blue );
	DestructableBlock( float x_coord, float y_coord,
		float set_width, float set_height );
	DestructableBlock( float x_coord, float y_coord,
		float set_width, float set_height,
		float red, float green, float blue );
	
	//getter
	Color &get_color() { return &color; }
	
	//override function
	void force_draw();
	void force_animate();
	bool ball_collision( Ball &ball );
}

#endif

