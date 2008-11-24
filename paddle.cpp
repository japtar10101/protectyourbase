#include "paddle.h"

/**** LOTS of constructors ****/

Paddle::Paddle() :
Block(), color(), horizontal( true ) {
	lower_limit = x;
	upper_limit = x + default_range;
}

Paddle::Paddle( float range_of_movement, bool move_horizontal ) :
Block(), color(), horizontal( move_horizontal ) {
	if( horizontal ) {
		lower_limit = x;
		upper_limit = x + range_of_movement;
	} else {
		lower_limit = y;
		upper_limit = y + range_of_movement;
	}
}

Paddle::Paddle( float range_of_movement, bool move_horizontal,
	float red, float green, float blue ) :
Block(),
color( red, green, blue ),
horizontal( move_horizontal ) {
	if( horizontal ) {
		lower_limit = x;
		upper_limit = x + range_of_movement;
	} else {
		lower_limit = y;
		upper_limit = y + range_of_movement;
	}
}

Paddle::Paddle( float x_coord, float y_coord,
	float range_of_movement, bool move_horizontal ) :
Block( x_coord, y_coord ),
color(),
horizontal( move_horizontal ) {
	if( horizontal ) {
		lower_limit = x_coord;
		upper_limit = x_coord + range_of_movement;
	} else {
		lower_limit = y_coord;
		upper_limit = y_coord + range_of_movement;
	}
}

Paddle::Paddle( float x_coord, float y_coord,
	float set_width, float set_height,
	float range_of_movement, bool move_horizontal ) :
Block( x_coord, y_coord, set_width, set_height ),
color(),
horizontal( move_horizontal ) {
	if( horizontal ) {
		lower_limit = x_coord;
		upper_limit = x_coord + range_of_movement;
	} else {
		lower_limit = y_coord;
		upper_limit = y_coord + range_of_movement;
	}
}

Paddle::Paddle( float x_coord, float y_coord,
	float set_width, float set_height,
	float range_of_movement, bool move_horizontal,
	float red, float green, float blue ) :
Block( x_coord, y_coord, set_width, set_height ),
color( red, green, blue ),
horizontal( move_horizontal ) {
	if( horizontal ) {
		lower_limit = x_coord;
		upper_limit = x_coord + range_of_movement;
	} else {
		lower_limit = y_coord;
		upper_limit = y_coord + range_of_movement;
	}
}

/**** Getter and Setter ****/

Color &Paddle::get_color() {
	return color;
}

void Paddle::set_upper_limit( float limit ) {
	if( limit < 0.0 ) limit = 0.0;
	if( limit < lower_limit ) upper_limit = lower_limit;
	else upper_limit = limit;
}

void Paddle::set_lower_limit( float limit ) {
	if( limit < 0.0 ) limit = 0.0;
	if( limit > upper_limit ) lower_limit = upper_limit;
	else lower_limit = limit;
}

void Paddle::set_limit( float lower, float upper ) {
	if( lower < 0.0 ) lower = 0.0;
	if( upper < 0.0 ) upper = 0.0;
	if( lower > upper ) lower_limit = upper_limit = lower;
	else {
		lower_limit = lower;
		upper_limit = upper;
	}
}

/**** functions that moves the paddle ****/

void Paddle::move_up() {
	if( !horizontal ) {
		y += velocity;
		//make sure y is in range
		if( y > upper_limit )
			y = upper_limit;
	}
}

void Paddle::move_down() {
	if( !horizontal ) {
		y -= velocity;
		//make sure y is in range
		if( y < lower_limit )
			y = lower_limit;
	}
}

void Paddle::move_right() {
	if( horizontal ) {
		x += velocity;
		//make sure x is in range
		if( x > upper_limit )
			x = upper_limit;
	}
}

void Paddle::move_left() {
	if( horizontal ) {
		x -= velocity;
		//make sure x is in range
		if( x < lower_limit )
			x = lower_limit;
	}
}

/**** Functions to override ****/

void Paddle::force_draw() {
	color.color();
	Block::force_draw();
}

bool Paddle::ball_collision( Ball &ball ) {
	bool collide = Block::ball_collision( ball );
	if( collide ) ball.increase_velocity();
	return collide;
}

