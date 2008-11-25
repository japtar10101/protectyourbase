#include "control.h"

Control::Control( bool player_one ) {
	//set controls
	if( player_one )
		controls = { 'w', 'W', 's', 'S', 'a', 'A', 'd', 'D' };
	else
		controls = { 'p', 'P', ';', ':', 'l', 'L', '\'', '"' };
	
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
