#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game : public Graphic {
private:
	Ball *ball;
	Player *p_one, *p_two;
	
	//helper functions
	void destroy_all();
	bool collision();
public:
	//public enumerators
	enum Formation { horizontal, vertical, diagonal };
	enum Victory { neither, player1, player2 };
	
	//Constructor & Destructor
	Game( Formation game_settings, Color *color1, Control *move1, Color *color2,
		Control *move2, Color *level1, Color *level2, Color *level3 );
	~Game();
	
	//Function indicating if anyone one, and if so, who.
	Victory winner();
	
	//Helper functions for controls
	void move_player_one() { p_one->move_paddle(); }
	void move_player_two() { p_two->move_paddle(); }
	
	//Functions that has to be overridden
	void force_draw();
	void force_animate();
	float top();
	float right();
};

#endif
