#include "destructible_block.h"

/**** LOTS of constructors ****/

DestructibleBlock::DestructibleBlock() : Block(), color() {}

DestructibleBlock::DestructibleBlock( float red, float green,
	float blue ) : Block(), color( red, green, blue ) {}

DestructibleBlock::DestructibleBlock( float x_coord, float y_coord ) :
Block( x_coord, y_coord ), color() {}

DestructibleBlock::DestructibleBlock(  float x_coord, float y_coord,
	float red, float green, float blue ) :
Block( x_coord, y_coord ), color( red, green, blue ) {}

DestructibleBlock::DestructibleBlock( float x_coord, float y_coord,
	float set_width, float set_height ) :
Block( x_coord, y_coord, set_width, set_height ), color() {}

DestructibleBlock::DestructibleBlock( float x_coord, float y_coord,
	float set_width, float set_height,
	float red, float green, float blue ) :
Block( x_coord, y_coord, set_width, set_height ),
color( red, green, blue ) {}

/**** Getter ****/
Color &DestructibleBlock::get_color() {
	return color;
}

/**** Functions to override ****/

void DestructibleBlock::force_draw() {
	color.color();
	Block::force_draw();
}

void DestructibleBlock::force_animate() {
	hide();
	Block::force_animate();
}

bool DestructibleBlock::ball_collision( Ball &ball ) {
	bool collide = Block::ball_collision( ball );
	if( collide ) play_animation();
	return collide;
}