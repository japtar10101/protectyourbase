#include "player.h"

/**** Contructor & Destructor ****/

Player::Player( Corner corner1, Corner corner2,
	float red, float green, float blue ) :
Graphic(), base_color( new Color( red, green, blue ) ) {
	first = new Base( corner1, base_color );
	second = new Base( corner2, base_color );
}

Player::Player( Corner corner1, Corner corner2, Color *color ) :
Graphic(), color( color ), first( corner1, color ), second( corner2, color ) {}

Player::~Player() {
	DESTROY( color );
	DESTROY( first );
	DESTROY( second );
}

/**** move functions ****/
//TODO
