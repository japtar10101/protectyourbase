#include <ctime>

#include "game.h"

/**** initialize variables ****/

const char *window_title = "Protect Your Base";
ProtectYourBase *protect_your_base;
Control *control1, *contro2;
Mouse *mouse;
bool holding_mouse;

/**** initialize functions ****/
void display();
void animation( int );
void push( unsigned char, int, int );
void raise( unsigned char, int, int );
void mouse( int, int, int, int );
void initialize_window();
void initialize_pointers();
void set_window_size( GLsizei, GLsizei );

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
	
	//mouse function
	glutMouseFunc( mouse );
	
	//changing window size
	glutReshapeFunc( set_window_size );
	
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
	if( protect_your_base->in_menu_mode() ) {
		if( holding_mouse )	glutTimerFunc( 100, animation, 0 );
		else				glutTimerFunc( 1, animation, 0 );
	}
}

//controls functions
void push( unsigned char key, int x, int y ) {
	if( !control1->push_key( key ) ) control2->push_key( key );
}

void raise( unsigned char key, int x, int y ) {
	if( !control1->raise_key( key ) ) control2->raise_key( key );
}

void mouse( int btn, int state, int x, int y ) {
	mouse->set_state( btn, state, x, y );
	if( state == GLUT_DOWN ) {
		holding_mouse = true;
	} else {
		holding_mouse = false;
	}
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
	//make controls
	control1 = new Control( player_one_controls );
	control2 = new Control( player_two_controls );
	
	//make the main game
	protect_your_base =  new Game( Game::vertical,
		color_one, control1, color_two, control2,
		level1, level2, level3 );
}

/*
void set_window_size( GLsizei w, GLsizei h ) {
	window_size_width = (int) w;
	window_size_height = (int) h;
}
*/
