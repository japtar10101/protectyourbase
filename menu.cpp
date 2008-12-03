#include "menu.h"

/**** constructors & destructors ****/

Menu::Menu( Game::Formation game_settings, Game::Victory game_text,
	Mouse *menu, Color *color1, Color *color2 ) :
Graphic( 0.0, 0.0, true, true ), text_mode( game_text ),
formation_mode( game_settings ), base1( color1 ), base2( color2 ),
start_game_color( new Color( 1.0, 1.0, 1.0 ) ), menu_controls( menu ),
start_game( new Block( start_x_placement, start_y_placement, start_width, start_height ) ) {
	unsigned char index = 0;
	
	//making color blocks
	portray_color[index++] = new Block( color_block_x_placement,
		color_block_y_placement, color_block_size, color_block_size );
	
	portray_color[index++] = new Block(
		grid_width - color_block_size - color_block_x_placement,
		color_block_y_placement, color_block_size, color_block_size );
	
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
	DESTROY( start_game_color );
	DESTROY( start_game );
	//menu controls will not be owned by menu
	//DESTROY( menu_controls );
}

void Menu::draw_color_blocks() {
	unsigned char index = 0;
	base1->color();
	portray_color[index++]->draw();
	base2->color();
	portray_color[index++]->draw();
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

//TODO: make text
void Menu::draw_start() {
	//draw static text (color & formation)
	
	//draw block
	start_game_color->color();
	start_game->draw();
}

/**** menu functions ****/

void Menu::draw_menu() {
	//draw_text();
	draw_color_blocks();
	draw_formation_blocks();
	draw_start();
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
	const MouseControl::Button btn = menu_controls->get_button();
	if( portray_color[0]->mouse_over( menu_controls ) ) {
		if( btn == MouseControl::left )
			toggle_color( true, true );
		else if( btn == MouseControl::right )
			toggle_color( true, false );
	} else if( portray_color[1]->mouse_over( menu_controls ) ) {
		if( btn == MouseControl::left )
			toggle_color( false, true );
		else if( btn == MouseControl::right )
			toggle_color( false, false );
	}
}

void Menu::toggle_formation() {
	const MouseControl::Button btn = menu_controls->get_button();
	const float bottom = formation[0]->bottom(), left = formation[0]->left(),
		top = formation[2]->top(), right = formation[2]->right(),
		mouse_x = menu_controls->get_x(), mouse_y = menu_controls->get_y();
	if( ( mouse_y > bottom && mouse_y < top ) &&
		( mouse_x > left && mouse_x < right ) ) {
		if( btn == MouseControl::left )
			toggle_formation( true );
		else if( btn == MouseControl::right )
			toggle_formation( false );
	}
}

bool Menu::start_end_game() {
	const MouseControl::Button btn = menu_controls->get_button();
	if( start_game->mouse_over( menu_controls ) ) {
		if( btn == MouseControl::left )
			return true;
		else if( btn == MouseControl::right )
			exit( 0 );
	}
	return false;
}

/**** overriding functions ****/

void Menu::force_draw() {
	draw_menu();
}

void Menu::force_animate() {
	toggle_color();
	toggle_formation();
}

float Menu::top() { return grid_height; }

float Menu::right() { return grid_width; }

