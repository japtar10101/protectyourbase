#include "control.h"

Control::Control( const unsigned char *array ) {
	//set the controls
	for( unsigned char index = 0; index < 8; ++index )
		controls[index] = array[index];
	
	//set all conditions to false
	for( unsigned char index = 0; index < 4; ++index )
		conditions[index] = false;
}

bool Control::push_key( unsigned char key ) {
	for( unsigned char index = 0; index < 8; ++index ) {
		if( controls[index] == key ) {
			conditions[index / 2] = true;
			return true;
		}
	}
	return false;
}

bool Control::raise_key( unsigned char key ) {
	for( unsigned char index = 0; index < 8; ++index ) {
		if( controls[index] == key ) {
			conditions[index / 2] = false;
			return true;
		}
	}
	return false;
}

bool Control::any_key_pressed() {
	for( unsigned char index = 0; index < 4; ++index ) {
		if( conditions[index] )
			return true;
	}
	return false;
}
