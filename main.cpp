#include <ctime>

#include "game.h"

/**** initialize variables ****/

const char *window_title = "Protect Your Base";
Game *protect_your_base;
Color *color_one, *color_two, *level1, *level2, *level3;
Control *control_one, *control_two;

/**** initialize functions ****/
void display();
void animation( int );
void push( unsigned char, int, int );
void raise( unsigned char, int, int );
void initialize_window();
void initialize_pointers();

/**** main function ****/

int main( int argc, char** argv ) {
	//setup the random seed and game
	srand( time( NULL ) );
	initialize_pointers();
	
	//basic setup
	glutInit( &argc, argv );
	
	//window setup
	initialize_window();
	
	//draw functions
	glutDisplayFunc( display );
	
	//animation function
	glutTimerFunc( 1, animation, 0 );
	
	//keyboard function
	glutKeyboardFunc( push );
	glutKeyboardUpFunc( raise );
	
	//go! main loop!
	glutMainLoop();
	
	return 0;
}

/**** define functions ****/

//make the display function
void display() {
	glClear( GL_COLOR_BUFFER_BIT );
		protect_your_base->draw();
	glutSwapBuffers();
	glutPostRedisplay();
}

//set the animations
void animation( int value ) {
	protect_your_base->animate();
	glutTimerFunc( 1, animation, 0 );
}

//controls functions
void push( unsigned char key, int x, int y ) {
	if( !control_one->push_key( key ) ) control_two->push_key( key );
}

void raise( unsigned char key, int x, int y ) {
	if( !control_one->raise_key( key ) ) control_two->raise_key( key );
}

//quick initialize window function
void initialize_window() {
	//initialize mode
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	
	//window position and size
	glutInitWindowPosition( window_position_x,
		window_position_y );
	glutInitWindowSize( window_size_width,
		window_size_height );
	glutCreateWindow( window_title );
	
	//State the game has no depth
	glDisable( GL_DEPTH_TEST );
	
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

//quick initialize pointers
void initialize_pointers() {
	//make colors
	level1 = new Color( 1.0, 0.0, 0.0 );
	level2 = new Color( 1.0, 0.5, 0.0 );
	level3 = new Color( 1.0, 1.0, 0.0 );
	color_one = new Color( 0.0, 1.0, 0.0 );
	color_two = new Color( 0.0, 0.0, 1.0 );
	
	//make controls
	control_one = new Control( player_one_controls );
	control_two = new Control( player_two_controls );
	
	//make the main game
	protect_your_base =  new Game( Game::vertical,
		color_one, control_one, color_two, control_two,
		level1, level2, level3 );
}

