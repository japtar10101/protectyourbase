#include "image.h"

Image::Image( std::string location ) : url( location ), o( 1.0 ) {}

Image::Image( std::string location, float opacity ) :
url( location ), o( opacity ) {
	//make sure opacity is in range
	if( o > 1.0 ) { o = 1.0; }
	else if( o < 0.0 ) { o = 0.0; }
}

void Image::set_opacity( float opacity ) {
	if( opacity > 1.0 ) { o = 1.0; }
	else if( opacity < 0.0 ) { o = 0.0; }
	else { o = opacity; }
}

bool Image::is_visible() {
	return o > 0.0;
}

