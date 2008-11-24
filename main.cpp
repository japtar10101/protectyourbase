#include <ctime>

#include "base.h"

/**** initialize variables ****/
const char *window_title = "The Game!!!";
Ball *ball;
Base *one;
Base *two;
Base *three;
Base *four;

//make the display function
void display() {
	glClear( GL_COLOR_BUFFER_BIT );
	ball->draw();
	one->draw();
	two->draw();
	three->draw();
	four->draw();
	glutSwapBuffers();
	glutPostRedisplay();
}

//set the animations
void animation( int value ) {
	//is the ball going to bounce off a wall?
	if( ball->right() > grid_width || ball->left() < 0 )
		ball->bounce_horizontally();
	if( ball->top() > grid_height || ball->bottom() < 0 )
		ball->bounce_vertically();
	one->ball_collision( ball );
	two->ball_collision( ball );
	three->ball_collision( ball );
	four->ball_collision( ball );
	//animate and redisplay.
	one->animate();
	two->animate();
	three->animate();
	four->animate();
	ball->animate();
	display();
	glutTimerFunc( 1, animation, 0 );
}

void controls( unsigned char key, int x, int y ) {
	//DEBUG_VAR( "key = %c", key );
	
	if( key == 'w' ) {
		one->move_up();
		two->move_up();
		three->move_up();
		four->move_up();
	} else if( key == 's' ) {
		one->move_down();
		two->move_down();
		three->move_down();
		four->move_down();
	}
	
	if( key == 'd' ) {
		one->move_right();
		two->move_right();
		three->move_right();
		four->move_right();
	} else if( key == 'a' ) {
		one->move_left();
		two->move_left();
		three->move_left();
		four->move_left();
	}
}

void initialize_window() {
	//window position and size
	glutInitWindowPosition( window_position_x,
		window_position_y );
    glutInitWindowSize( window_size_width,
		window_size_height );
	//setup functions
	glutCreateWindow( window_title );
	glutDisplayFunc( display );
	//adjust clipping box
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, grid_width, 0.0, grid_height, -1.0, 1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	//adjust viewport and clear
	glViewport( 0, 0, grid_width, grid_height );
	glClearColor( 0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT );
}

int main( int argc, char** argv ) {
	//setup the random variable for Ball constructor
	srand( time( NULL ) );
	ball =  new Ball( ball_radius, grid_height / 2.0, grid_width / 2.0, beginning_velocity );
	one = new Base( Base::top_right, 0.0, 0.0, 1.0 );
	two = new Base( Base::top_left, 0.0, 0.0, 1.0 );
	three = new Base( Base::bottom_left, 0.0, 0.0, 1.0 );
	four = new Base( Base::bottom_right, 0.0, 0.0, 1.0 );
	//basic setup
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	//animation function
	glutTimerFunc( 1, animation, 0 );
	//window setup
	initialize_window();
	//keyboard function
	glutKeyboardFunc( controls );
	//go! main loop!
	glutMainLoop();
	return 0;
}
