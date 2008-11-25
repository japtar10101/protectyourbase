#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game : public Graphic {
private:
	//private enumerator (here for a reason)
	enum Mode { game, menu };
	
	//internal variables
	Ball *ball;
	Player *p_one, *p_two;
	Color *c_one, *c_two;
	Mode current_state;
	
	//helper functions
	void destroy_all();
	bool collision();
public:
	//public enumerators
	enum Formation { horizontal, vertical, diagonal };
	enum Victory { neither, player1, player2 };
	
	//Constructor
	Game( Formation game_settings, Color *color1, Color *color2 );
	
	//Destructor
	~Game();
	
	//Function indicating if anyone one, and if so, who.
	Victory winner();
	
	//Helper functions for controls
	void move_player_one_up() { p_one->move_up(); }
	void move_player_one_down() { p_one->move_down(); }
	void move_player_one_right() { p_one->move_right(); }
	void move_player_one_left() { p_one->move_left(); }
	void move_player_two_up() { p_two->move_up(); }
	void move_player_two_down() { p_two->move_down(); }
	void move_player_two_right() { p_two->move_right(); }
	void move_player_two_left() { p_two->move_left(); }
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif

