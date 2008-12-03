#ifndef MOUSE_H
#define MOUSE_H

#define OUT_OF_BOUNDS (-1)

struct MouseControl {
	//everything is public in structs
	//variables
	int x, y, btn, ud;
	
	//enums
	enum Button { left, middle, right, none };
	enum State { up, down };
	
	//constructor
	MouseControl( int button, int up_down, int x_pos, int y_pos );
	
	//setter
	void change_state( int button, int up_down, int x_pos, int y_pos );
	
	//state function
	Button button();
	State state();
};

class Mouse {
private:
	MouseControl control;
	
public:
	static int mouse_range_width, mouse_range_height;
	
	//Constructor
	Mouse();
	
	//functions for keyboard
	void set_state( int button, int state, int x, int y ) {
		control.change_state( button, state, x, y );
	}
	
	//function that gets the button pressed, if any
	MouseControl::Button get_button();
	
	//function that says that at least one button is pressed
	bool any_button_pressed() {
		return control.state() == MouseControl::down;
	}
	
	//get coordinates
	float get_x();
	float get_y();
};

#endif

