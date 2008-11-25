#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu : public Graphic {
private:
	//internal variables
	Game::Formation game_mode;
	
	Color *color1, *color2;
	Control *player1, *player2, *menu_controls;
	
	//variables for visuals
	Block *formation[4];
	Block *portray_color[2];
	
	//helper functions
	void destroy_all();
public:
	//public enumerators
	enum BaseColor { red, orange, yellow, green, blue, violet };
	
	//Constructor & Destructor
	Menu( Game::Formation game_settings, Color *color1, Control *move1,
		Color *color2, Control *move2 );
	~Menu();
	
	//Helper functions for controls
	void toggle_color1( bool up );
	void toggle_color2( bool up );
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif
