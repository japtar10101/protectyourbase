#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
	/*
	variables:
	image location, opacity
	*/
	std::string url;
	float o;
	
public:
	/*
	Constructor:
	default opacity is fully visible
	*/
	Image( std::string location );
	Image( std::string location, float opacity );
	
	//setters and getters
	void set_url( std::string location ) { url = location; }
	void set_opacity( float opacity );
	std::string get_url() { return url; }
	float get_opacity() { return o; }
	
	//testing function
	bool is_visible();
	
	//TODO: set the polygon image
	//void image() { glColor3f( r, g, b ); }
};

#endif

