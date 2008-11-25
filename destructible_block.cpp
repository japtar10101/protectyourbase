#include "destructible_block.h"

GLuint DestructibleBlock::display_list_id;

/**** constructors and destructor ****/

DestructibleBlock::DestructibleBlock( float x_coord, float y_coord,
	float set_width, float set_height,
	Color *block_color ) :
Block( x_coord, y_coord, set_width, set_height ), id( 0 ),
color( block_color ) {}

DestructibleBlock::~DestructibleBlock() {
	DESTROY( color );
}

/**** Getter ****/
Color *DestructibleBlock::get_color() {
	return color;
}

void DestructibleBlock::gl_compile() {
	glNewList( id, GL_COMPILE );
		normal_draw();
	glEndList();
    glCallList( id );
}

void DestructibleBlock::normal_draw() {
	glBegin( GL_QUADS );
		color->color();
		glVertex2f( x, y );
		glVertex2f( x, y + height );
		glVertex2f( x + width, y + height );
		glVertex2f( x + width, y );
	glEnd();
}

/**** Functions to override ****/

void DestructibleBlock::force_draw() {
    if( id == 0 ) {
        id = display_list_id++;
        gl_compile();
    } else glCallList( id );
}

void DestructibleBlock::force_animate() {
	hide();
	Block::force_animate();
}

bool DestructibleBlock::ball_collision( Ball *ball ) {
	if( Block::ball_collision( ball ) ) {
        play_animation();
        ball->increase_velocity();
        return true;
    } else return false;
}
