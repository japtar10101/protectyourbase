#ifndef COLOR_H
#define COLOR_H

struct Color {
	/*
	variables:
	red, green, blue, opacity
	*/
	float r, g, b, o;
	
	/*
	Constructor:
	default color is black, default opacity is fully visible
	*/
	Color();
	Color( float red, float green, float blue );
	Color( float red, float green, float blue, float opacity );
	
	//small function
	bool is_visible();
}

#endif

