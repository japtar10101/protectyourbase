#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game : public Graphic {
private:
	//private enumerator (here for a reason)
	enum Mode { game, menu };
	
	//internal variables
	Color *c_one, *c_two;
	Control *m_one, *m_two;
	
	Ball *ball;
	Player *p_one, *p_two;
	Mode current_state;
	
	//helper functions
	void destroy_all();
	bool collision();
public:
	//public enumerators
	enum Formation { horizontal, vertical, diagonal };
	enum Victory { neither, player1, player2 };
	
	//Constructor & Destructor
	Game( Formation game_settings, Color *color1, Control *move1,
		Color *color2, Control *move2 );
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

