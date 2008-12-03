#include "protect_your_base.h"

/**** constructor & destructor ****/

ProtectYourBase::ProtectYourBase( Mouse *mouse_controls, Control *move1, Control *move2 ) :
Graphic( 0.0, 0.0, true, true ),
mouse( mouse_controls ),
player1( move1 ), player2( move2 ),
color1( new Color( all_colors[0][0], all_colors[0][1], all_colors[0][2] ) ),
color2( new Color( all_colors[4][0], all_colors[4][1], all_colors[4][2] ) ),
level1( NULL ), level2( NULL ), level3( NULL ),
game( NULL ), menu( NULL ),
formation( Game::vertical ), victory( Game::neither ) {
	menu = new Menu( formation, victory, mouse, color1, color2 );
}

ProtectYourBase::~ProtectYourBase() {
	destroy_all();
}

/**** helper functions ****/

void ProtectYourBase::destroy_all() {
	DESTROY( color1 );
	DESTROY( color2 );
	DESTROY( level1 );
	DESTROY( level2 );
	DESTROY( level3 );
	DESTROY( game );
	DESTROY( menu );
}

void ProtectYourBase::switch_to_menu() {
	//grab info
	victory = game->winner();
	
	//destroy game
	DESTROY( level1 );
	DESTROY( level2 );
	DESTROY( level3 );
	DESTROY( game );
	
	//make menu
	menu = new Menu( formation, victory, mouse, color1, color2 );
}

void ProtectYourBase::switch_to_game() {
	//grab info
	formation = menu->get_formation();
	victory = Game::neither;
	
	//destroy menu
	DESTROY( menu );
	
	//make menu
	level1 = new Color( 1.0, 0.0, 0.0 );
	level2 = new Color( 1.0, 0.5, 0.0 );
	level3 = new Color( 1.0, 1.0, 0.0 );
	game = new Game( formation, color1, player1, color2, player2,
		level1, level2, level3 );
}

/**** Public functions ****/

void ProtectYourBase::switch_modes() {
	if( in_menu_mode() )
		switch_to_game();
	else
		switch_to_menu();
}

bool ProtectYourBase::in_menu_mode() {
	if( menu )	return true;
	else		return false;
}

/**** functions to override ****/

void ProtectYourBase::force_draw() {
	if( in_menu_mode() )
		menu->draw();
	else
		game->draw();
}

void ProtectYourBase::force_animate() {
	if( in_menu_mode() ) {
		menu->animate();
		//DEBUG( "menu animate" );
		if( menu->start_end_game() )
			switch_modes();
	} else {
		game->animate();
		//DEBUG( "game animate" );
		if( game->winner() != Game::neither )
			switch_modes();
	}
}

float ProtectYourBase::top() {
	return grid_height;
}

float ProtectYourBase::right() {
	return grid_width;
}

