#include <ctime>

#include "ball.h"
#include "destructible_block.h"
#include "paddle.h"

/**** initialize variables ****/
const char *window_title = "The Game!!!";
Ball ball;
Block testing;
DestructibleBlock testing2;
Block testing3;
DestructibleBlock testing4;
Paddle vertical;
Paddle horizontal;

//make the display function
void display() {
	glClear( GL_COLOR_BUFFER_BIT );
	ball.draw();
	testing.draw();
	testing3.draw();
	testing2.draw();
	testing4.draw();
	vertical.draw();
	horizontal.draw();
	glutSwapBuffers();
	glutPostRedisplay();
}

//set the animations
void animation( int value ) {
	bool increase_velocity = false;
	//is the ball going to bounce off a wall?
	if( ball.right() > width || ball.left() < 0 ) {
		ball.bounce_horizontally();
		increase_velocity = true;
	}
	if( ball.top() > height || ball.bottom() < 0 ) {
		ball.bounce_vertically();
		increase_velocity = true;
	}
	testing.ball_collision( ball );
	testing2.ball_collision( ball );
	testing3.ball_collision( ball );
	testing4.ball_collision( ball );
	vertical.ball_collision( ball );
	horizontal.ball_collision( ball );
	//should we increment the speed?
	if( increase_velocity ) ball.increase_velocity();
	//animate and redisplay.
	ball.animate();
	testing.animate();
	testing2.animate();
	testing3.animate();
	testing4.animate();
	display();
	glutTimerFunc( 1, animation, 0 );
}

void controls( unsigned char key, int x, int y ) {
	DEBUG_VAR( "key = %c", key );
	
	if( key == 'w' ) {
		DEBUG( "Going up" );
		vertical.move_up();
	} else if( key == 's' ) {
		DEBUG( "Going down" );
		vertical.move_down();
	}
	
	if( key == 'd' ) {
		DEBUG( "Going right" );
		horizontal.move_right();
	} else if( key == 'a' ) {
		DEBUG( "Going left" );
		horizontal.move_left();
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
	glOrtho( 0.0, width, 0.0, height, -1.0, 1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	//adjust viewport and clear
	glViewport( 0, 0, width, height );
	glClearColor( 0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT );
}

int main( int argc, char** argv ) {
	//setup the random variable for Ball constructor
	srand( time( NULL ) );
	ball = Ball( ball_radius, height / 2.0, width / 2.0, beginning_velocity );
	testing = Block( 5.0, 5.0, 2.0, 2.0 );
	testing2 = DestructibleBlock( 13.0, 5.0, 2.0, 2.0, 1.0, 0.0, 0.0 );
	testing3 = Block( 5.0, 13.0, 2.0, 2.0 );
	testing4 = DestructibleBlock( 13.0, 13.0, 2.0, 2.0, 0.0, 0.0, 1.0 );
	vertical = Paddle( 0.0, 0.0, 1.0, 4.0, 16.0, false, 0.0, 1.0, 0.0 );
	horizontal = Paddle( 0.0, 0.0, 4.0, 1.0, 16.0, true, 0.0, 1.0, 0.0 );
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
