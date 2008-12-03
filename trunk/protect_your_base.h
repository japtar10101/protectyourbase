#ifndef PROTECT_YOUR_BASE_H
#define PROTECT_YOUR_BASE_H

#include "menu.h"
#include "game.h"

class ProtectYourBase : public Graphic {
private:
	Mouse *mouse;
	Control *player1, *player2;
	
	unsigned char color_index1, color_index2;
	Color *color1, *color2, *level1, *level2, *level3;
	
	Game *game;
	Menu *menu;
	
	Game::Formation formation;
	Game::Victory victory;
	
	//helper functions
	void destroy_all();
	void switch_to_menu();
	void switch_to_game();
	void set_color_index();
public:
	//Constructor & Destructor
	ProtectYourBase( Mouse *mouse_controls, Control *move1, Control *move2 );
	~ProtectYourBase();
	
	//function used to switch between different modes
	void switch_modes();
	
	//returns true if in menu mode
	bool in_menu_mode();
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif
