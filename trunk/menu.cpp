#include "menu.h"

static const float all_colors[6][3] = {
	{ 1.0, 0.0, 0.0 }	//red
	, { 1.0, 0.5, 0.0 }	//orange
	, { 1.0, 1.0, 0.0 }	//yellow
	, { 0.0, 1.0, 0.0 }	//green
	, { 0.0, 0.0, 1.0 }	//blue
	, { 1.0, 0.0, 1.0 }	//violet
};

/**** constructors & destructors ****/

Menu::Menu( Game::Formation game_settings, Game::Victory game_text,
	Control *menu, Color *color1, Control *move1, Color *color2,
	Control *move2 ) : Graphic(), menu_mode( settings ), text_mode( game_text ),
formation_mode( game_settings ), base1( color1 ), base2( color2 ),
player1( move1 ), player2( move2 ), menu_controls( menu ) {
	unsigned char index = 0;
	
	//making color blocks
	portray_color[index++] = new Block( color_block_x_placement,
		color_block_y_placement, color_block_size, color_block_size );
	
	portray_color[index++] = new Block( grid_width - color_block_x_placement,
		grid_height - color_block_y_placement, color_block_size,
		color_block_size );
	
	//making formation blocks (clockwise)
	index = 0;
	const float formation_x_placement = grid_width / 2.0 - formation_size / 2.0,
		formation_block_size = formation_size / 3.0;
	formation[index++] = new Block(
		formation_x_placement,
		formation_y_placement,
		formation_block_size,
		formation_block_size );
	formation[index++] = new Block(
		formation_x_placement,
		formation_y_placement + formation_block_size * 2,
		formation_block_size,
		formation_block_size );
	formation[index++] = new Block(
		formation_x_placement + formation_block_size * 2,
		formation_y_placement + formation_block_size * 2,
		formation_block_size,
		formation_block_size );
	formation[index++] = new Block(
		formation_x_placement + formation_block_size * 2,
		formation_y_placement,
		formation_block_size,
		formation_block_size );
}

Menu::~Menu() {
	destroy_all();
}

/**** private functions ****/

void Menu::destroy_all() {
	unsigned char index;
	for( index = 0; index < 4; ++index )
		DESTROY( formation[index] );
	for( index = 0; index < 2; ++index )
		DESTROY( portray_color[index] );
	DESTROY( menu_controls );
}

void Menu::draw_color_blocks() {
	for( unsigned char index = 0; index < 2; ++index )
		portray_color[index]->draw();
}

void Menu::draw_formation_blocks() {
	unsigned char index = 0;
	switch( formation_mode ) {
		case Game::horizontal:
			base2->color();
			formation[index++]->draw();
			base1->color();
			formation[index++]->draw();
			formation[index++]->draw();
			base2->color();
			formation[index++]->draw();
			break;
		case Game::diagonal:
			base2->color();
			formation[index++]->draw();
			base1->color();
			formation[index++]->draw();
			base2->color();
			formation[index++]->draw();
			base1->color();
			formation[index++]->draw();
			break;
		case Game::vertical:
		default:
			base1->color();
			formation[index++]->draw();
			formation[index++]->draw();
			base2->color();
			formation[index++]->draw();
			formation[index++]->draw();
	}
}

//TODO: make text
void Menu::draw_text() {
	return;
	//draw static text (color & formation)
	
	//draw title
	switch( text_mode ) {
		case Game::player1:
			break;
		case Game::player2:
			break;
		case Game::neither:
		default:
			break;
	}
}

/**** menu functions ****/

void Menu::draw_menu() {
	draw_text();
	draw_color_blocks();
	draw_formation_blocks();
}

//TODO: make the help menu
void Menu::draw_help() {
	return;
	//draw player1 game controls
	//draw player2 game controls
	//draw menu controls
}

//TODO: make the credits menu
void Menu::draw_credits() {
	return;
	//draw names
	//draw description
	//draw special thanks
}

/**** toggling color and formation ****/

void Menu::toggle_color( bool player, bool up ) {
	//setup variables
	Color *to_modify = player ? base1 : base2;
	
	float red = to_modify->get_red(),
		green = to_modify->get_green(),
		blue = to_modify->get_blue();
	
	for( unsigned char index = 0; index < 6; ++index ) {
		//search for the matching color
		if( all_colors[index][0] == red &&
			all_colors[index][1] == green &&
			all_colors[index][2] == blue ) {
			//if already on the upper limit, set color back to start
			if( index == 5 && up ) {
				to_modify->set_color( all_colors[0][0],
					all_colors[0][1], all_colors[0][2] );
			//if on the lower limit, set color to end
			} else if( index == 0 && !up ) {
				to_modify->set_color( all_colors[5][0],
					all_colors[5][1], all_colors[5][2] );
			} else {
				if( up ) index++;
				else index--;
				to_modify->set_color( all_colors[index][0],
					all_colors[index][1], all_colors[index][2] );
			}
			break;
		}
	}
}

void Menu::toggle_formation( bool up ) {
	if( formation_mode == Game::horizontal ) {
		if( up )
			formation_mode = Game::vertical;
		else
			formation_mode = Game::diagonal;
	} else if( formation_mode == Game::vertical ) {
		if( up )
			formation_mode = Game::diagonal;
		else
			formation_mode = Game::horizontal;
	} else {
		if( up )
			formation_mode = Game::horizontal;
		else
			formation_mode = Game::vertical;
	}
}

/**** control functions ****/

void Menu::toggle_color() {
	if( player1->get_key_condition( Control::up ) )
		toggle_color( true, true );
	else if( player1->get_key_condition( Control::down ) )
		toggle_color( true, false );
	if( player2->get_key_condition( Control::up ) )
		toggle_color( false, true );
	else if( player2->get_key_condition( Control::down ) )
		toggle_color( false, false );
}

void Menu::toggle_formation() {
	if( player1->get_key_condition( Control::left ) )
		toggle_formation( false );
	else if( player1->get_key_condition( Control::right ) )
		toggle_formation( true );
	else if( player2->get_key_condition( Control::left ) )
		toggle_formation( false );
	else if( player2->get_key_condition( Control::right ) )
		toggle_formation( true );
}

void Menu::toggle_menu() {
	if( menu_controls->get_key_condition( Control::left ) ) {
		//toggle help menu
		if( menu_mode == help )
			menu_mode = settings;
		else
			menu_mode = help;
	} else if( menu_controls->get_key_condition( Control::right ) ) {
		//toggle credits menu
		if( menu_mode == credits )
			menu_mode = settings;
		else
			menu_mode = credits;
	}
}

bool Menu::start_end_game() {
	if( menu_controls->get_key_condition( Control::up ) )
		return true;  //start the game!
	else if( menu_controls->get_key_condition( Control::down ) )
		exit( 0 );  //end the game
	return false;
}

/**** overriding functions ****/

void Menu::force_draw() {
	switch( menu_mode ) {
		case help:
			draw_help();
			break;
		case credits:
			draw_credits();
			break;
		case settings:
		default:
			draw_menu();
	}
}

void Menu::force_animate() { stop_animation(); }

float Menu::top() { return grid_height; }

float Menu::right() { return grid_width; }
