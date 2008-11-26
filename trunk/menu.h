#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu : public Graphic {
private:
	//private enumerator for menu
	enum MenuMode { settings, help, credits };
	
	//constants for setup
	static const float color_block_x_placement = 6.0,
		color_block_y_placement = 4.0, color_block_size = 4.0,
		formation_y_placement = 10.0, formation_size = 9.0;
	
	//internal variables
	MenuMode menu_mode;
	Game::Victory text_mode;
	Game::Formation formation_mode;
	
	Color *base1, *base2;
	Control *player1, *player2, *menu_controls;
	
	//variables for visuals
	Block *formation[4];
	Block *portray_color[2];
public:
	//Constructor & Destructor
	Menu( Game::Formation game_settings, Game::Victory game_text, Control *menu,
		Color *color1, Control *move1, Color *color2, Control *move2 );
	~Menu();
	
	//Control functions
	void toggle_color();
	void toggle_formation();
	void toggle_menu();
	//start_end_game returns true if the players wants to
	//start the game
	bool start_end_game();
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
private:
	//helper functions
	void destroy_all();
	void draw_color_blocks();
	void draw_formation_blocks();
	void draw_text();
	
	//menu functions
	void draw_menu();
	void draw_help();
	void draw_credits();
	
	//toggling color and formation
	void toggle_color( bool player, bool up );
	void toggle_formation( bool up );
};

#endif
