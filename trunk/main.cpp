#include <ctime>

#include "game.h"

/**** initialize variables ****/

const char *window_title = "Protect your base";
Game *protect_your_base;
Color *color_one, *color_two;

/**** initialize functions ****/
void display();
void animation( int );
void controls( unsigned char, int, int );
void initialize_window();

/**** main function ****/

int main( int argc, char** argv ) {
	//setup the random seed and game
	srand( time( NULL ) );
	color_one = new Color( 0.0, 1.0, 0.0 );
	color_two = new Color( 0.0, 0.0, 1.0 );
	protect_your_base =  new Game( Game::vertical, color_one, color_two );
	
	//basic setup
	glutInit( &argc, argv );
	
	//window setup
	initialize_window();
	
	//draw functions
	glutDisplayFunc( display );
	
	//animation function
	glutTimerFunc( 1, animation, 0 );
	
	//keyboard function
	glutKeyboardFunc( controls );
	
	//go! main loop!
	glutMainLoop();
	
	return 0;
}

/**** define functions ****/

//make the display function
void display() {
	protect_your_base->draw();
}

//set the animations
void animation( int value ) {
	protect_your_base->animate();
	glutTimerFunc( 1, animation, 0 );
}

//controls functions
void controls( unsigned char key, int x, int y ) {
	if( key == 'w' ) {
		protect_your_base->move_player_one_up();
		protect_your_base->move_player_two_up();
	} else if( key == 's' ) {
		protect_your_base->move_player_one_down();
		protect_your_base->move_player_two_down();
	}
	
	if( key == 'd' ) {
		protect_your_base->move_player_one_right();
		protect_your_base->move_player_two_right();
	} else if( key == 'a' ) {
		protect_your_base->move_player_one_left();
		protect_your_base->move_player_two_left();
	}
}

void initialize_window() {
	//initialize mode
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	
	//window position and size
	glutInitWindowPosition( window_position_x,
		window_position_y );
    glutInitWindowSize( window_size_width,
		window_size_height );
	glutCreateWindow( window_title );
	
	//adjust clipping box
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, grid_width, 0.0, grid_height, -1.0, 1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	
	//adjust viewport and clear
	glViewport( 0, 0, grid_width, grid_height );
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glClear( GL_COLOR_BUFFER_BIT );
}

