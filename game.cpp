#include "game.h"

/**** Constructor and Destructor ****/

//TODO: initializer for immediate gameplay
//Make the menu the default soon
Game::Game( Formation game_settings, Color *color1, Control *move1,
	Color *color2, Control *move2 ) : Graphic( 0.0, 0.0, true, true ),
c_one( color1 ), c_two( color2 ), m_one( move1 ), m_two( move2 ),
ball( new Ball( ball_radius, grid_height / 2.0, grid_width / 2.0, beginning_velocity ) ),
current_state( game ) {
	//get the corresponding corners
	Base::Corner player1[2], player2[2];
	switch( game_settings ) {
		case horizontal:
			player1[0] = Base::top_left;
			player1[1] = Base::top_right;
			player2[0] = Base::bottom_left;
			player2[1] = Base::bottom_right;
			break;
		case vertical:
			player1[0] = Base::top_left;
			player1[1] = Base::bottom_left;
			player2[0] = Base::top_right;
			player2[1] = Base::bottom_right;
			break;
		case diagonal:
		default:
			player1[0] = Base::top_left;
			player1[1] = Base::bottom_right;
			player2[0] = Base::bottom_left;
			player2[1] = Base::top_right;
	}
	
	//setup the players
	DestructibleBlock::reset_display_list_id();
	p_one = new Player( player1[0], player1[1], c_one, m_one );
	p_two = new Player( player2[0], player2[1], c_two, m_two );
}

Game::~Game() {
	DESTROY( c_one );
	DESTROY( c_two );
	DESTROY( m_one );
	DESTROY( m_two );
	destroy_all();
}

/**** private helper functions ****/

void Game::destroy_all() {
	DESTROY( ball );
	DESTROY( p_one );
	DESTROY( p_two );
}

bool Game::collision() {
	bool collide = false;
	
	//is the ball going to bounce off a wall?
	if( ball->right() > grid_width || ball->left() < 0 ) {
		ball->bounce_horizontally();
        //ball->increase_velocity();
		collide = true;
	}
	if( ball->top() > grid_height || ball->bottom() < 0 ) {
		ball->bounce_vertically();
        //ball->increase_velocity();
		collide = true;
	}
	
	//what about the players?
	collide = collide ||
		p_one->ball_collision( ball ) || p_two->ball_collision( ball );
	
	//check if any player is alive
	if( winner() != neither ) current_state = menu;
	
	return collide;
}

/**** Victory declaration functions ****/

Game::Victory Game::winner() {
	if( !player1 && !player2 ) return neither;
	else if( !p_one->is_alive() ) return player1;
	else if( !p_two->is_alive() ) return player2;
	else                          return neither;
}

/**** Functions to override ****/

void Game::force_draw() {
	glClear( GL_COLOR_BUFFER_BIT );
	
	if( current_state == game ) {
		ball->draw();
		p_one->draw();
		p_two->draw();
	} else {
		//TODO: create a menu graphic
		ball->draw();
	}
	
	glutSwapBuffers();
	glutPostRedisplay();
}

void Game::force_animate() {
	if( current_state == game ) {
		collision();
		move_player_one();
		move_player_two();
		p_one->animate();
		p_two->animate();
		ball->animate();
	}
}

float Game::top() { return grid_height; }

float Game::right() { return grid_width; }

