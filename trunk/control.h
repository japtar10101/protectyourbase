#ifndef CONTROL_H
#define CONTROL_H

#include "global.h"

class Control {
private:
	unsigned char controls[8];
	bool conditions[4];
	
public:
	//Enumerator for movement
	enum Move { up = 0, down, right, left };
	
	//Constructor
	Control( const unsigned char *array );
	
	//functions for keyboard
	bool push_key( unsigned char key );
	bool raise_key( unsigned char key );
	
	//function that gets the key conditions
	bool get_key_condition( Move control ) { return conditions[control]; }
	
	//function that says that at least one key is pressed
	bool any_key_pressed();
};

#endif

