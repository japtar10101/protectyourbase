#include "destructable_block.h"

/**** LOTS of constructors ****/

DestructableBlock::DestructableBlock() : Block(), color() {}

DestructableBlock::DestructableBlock( float red, float green,
	float blue ) : Block(), color( red, green, blue ) {}

DestructableBlock::DestructableBlock( float x_coord, float y_coord ) :
Block( x_coord, y_coord ), color() {}

DestructableBlock::DestructableBlock(  float x_coord, float y_coord,
	float red, float green, float blue ) :
Block( x_coord, y_coord ), color( red, green, blue ) {}

DestructableBlock::DestructableBlock( float x_coord, float y_coord,
	float set_width, float set_height ) :
Block( x_coord, y_coord, set_width, set_height ), color() {}

DestructableBlock::DestructableBlock( float x_coord, float y_coord,
	float set_width, float set_height,
	float red, float green, float blue ) :
Block( x_coord, y_coord, set_width, set_height ),
color( red, green, blue ) {}

/**** Getter ****/
Color &DestructableBlock::get_color() {
	return color;
}

/**** Functions to override ****/

void DestructableBlock::force_draw() {
	color.color();
	Block::force_draw();
}

void DestructableBlock::force_animate() {
	hide();
	Block::force_animate();
}

bool DestructableBlock::ball_collision( Ball &ball ) {
	bool collide = Block::ball_collision( ball );
	if( collide ) play_animation();
	return collide;
}
