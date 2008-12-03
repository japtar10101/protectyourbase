#ifndef MENU_H
#define MENU_H

#include "game.h"
#include <cstring>

class Menu : public Graphic {
private:
	//constants for setup
	static const float color_block_x_placement = 4.0,
		color_block_y_placement = 4.0, color_block_size = 4.0,
		formation_y_placement = 10.0, formation_size = 9.0,
		start_x_placement = 12.0, start_y_placement = 4.5,
		start_width = 6.0, start_height = 3.0;
	
	//internal variables
	Game::Victory text_mode;
	Game::Formation formation_mode;
	
	Color *base1, *base2, *start_game_color;
	Mouse *menu_controls;
	
	//variables for visuals
	Block *formation[4];
	Block *portray_color[2];
	Block *start_game;
public:
	//Constructor & Destructor
	Menu( Game::Formation game_settings, Game::Victory game_text, Mouse *menu,
		Color *color1, Color *color2 );
	~Menu();
	
	//Control functions
	void toggle_color();
	void toggle_formation();
	//start_end_game returns true if the players wants to start the game
	bool start_end_game();
	Game::Formation get_formation() { return formation_mode; }
	
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
	void draw_string( float x, float y, const char *string );
	void draw_text();
	void draw_start();
	
	//menu functions
	void draw_menu();
	
	//toggling color and formation
	void toggle_color( bool player, bool up );
	void toggle_formation( bool up );
};

#endif
