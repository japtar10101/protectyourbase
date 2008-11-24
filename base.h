#ifndef BASE_H
#define BASE_H

#include "destructible_block.h"
#include "paddle.h"

class Base : public Graphic {
private:
	#define NUM_DESTRUCTIBLE_BLOCKS 7
	static const Color level_1_color( 1.0, 0.0, 0.0 );
	static const Color level_2_color( 1.0, 1.0, 0.0 );
	static const Color level_3_color( 0.0, 1.0, 0.0 );
	
	Color *base_color;
	Paddle *horizontal;
	Paddle *vertical;
	DestrutibleBlock *base;
	DestrutibleBlock *defense[NUM_DESTRUCTIBLE_BLOCKS];
public:
	//Corner enumerator
	enum Corner {
		top-right,
		top-left,
		bottom-right,
		bottom-left
	};
	
	//Constructor
	Base( Corner corner );
	Base( Corner corner, float red, float green, float blue );
	
	//Functions to move the paddles
	controls( unsigned char key );
	controls( bool key[256] );
	
	//Function for collision detection
	bool ball_collision( Ball &ball );
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif

