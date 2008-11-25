#ifndef DESTRUCTIBLE_BLOCK_H
#define DESTRUCTIBLE_BLOCK_H

#include "block.h"
#include "color.h"

class DestructibleBlock : public Block {
private:
	static int display_list_id;
	int id;
	Color *color;
	
	//Display list functions
	void gl_compile();
	void normal_draw();
public:
	//constructor & destructor
	DestructibleBlock( float x_coord, float y_coord,
		float set_width, float set_height,
		Color *block_color );
	~DestructibleBlock();
	
	//static function
	static void reset_display_list_id() { display_list_id = 1; }
	
	//getter
	Color *get_color();
	
	//override function
	void force_draw();
	void force_animate();
	bool ball_collision( Ball *ball );
};

#endif

