#include "destructible_block.h"

int DestructibleBlock::display_list_id;

/**** constructors and destructor ****/

DestructibleBlock::DestructibleBlock( float x_coord, float y_coord,
	float set_width, float set_height,
	Color *block_color ) :
Block( x_coord, y_coord, set_width, set_height ), id( display_list_id++ ),
color( block_color ) {
	gl_compile();
}

DestructibleBlock::~DestructibleBlock() {
	DESTROY( color );
}

/**** Getter ****/
Color *DestructibleBlock::get_color() {
	return color;
}

void DestructibleBlock::gl_compile() {
	glNewList( id, GL_COMPILE );
		if( color ) color->color();
		glBegin( GL_QUADS );
			glVertex2f( x, y );
			glVertex2f( x, y + height );
			glVertex2f( x + width, y + height );
			glVertex2f( x + width, y );
		glEnd();
	glEndList();
}

/**** Functions to override ****/

void DestructibleBlock::force_draw() {
	glCallList( id );
}

void DestructibleBlock::force_animate() {
	hide();
	Block::force_animate();
}

bool DestructibleBlock::ball_collision( Ball *ball ) {
	bool collide = Block::ball_collision( ball );
	if( collide ) play_animation();
	return collide;
}
