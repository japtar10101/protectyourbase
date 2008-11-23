#include <ctime>

#include "ball.h"
#include "destructable_block.h"

/**** initialize variables ****/
static const int window_size_width = 700, window_size_height = 700,
	//window_position_x = 400, window_position_y = 200;
	window_position_x = 0, window_position_y = 0;
static const char *window_title = "The Game!!!";
static const GLdouble width = 20, height = 20;
Ball ball;
Block testing;
DestructableBlock testing2;
Block testing3;
DestructableBlock testing4;

//make the display function
void display() {
	glClear( GL_COLOR_BUFFER_BIT );
	ball.draw();
	testing.draw();
	testing2.draw();
	testing3.draw();
	testing4.draw();
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
	ball = Ball();
	testing = Block( 5.0, 5.0, 2.0, 2.0 );
	testing2 = DestructableBlock( 13.0, 5.0, 2.0, 2.0, 1.0, 0.0, 0.0 );
	testing3 = Block( 5.0, 13.0, 2.0, 2.0 );
	testing4 = DestructableBlock( 13.0, 13.0, 2.0, 2.0, 0.0, 0.0, 1.0 );
	//basic setup
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
	//animation function
	glutTimerFunc( 1, animation, 0 );
	//window setup
	initialize_window();
	//go! main loop!
	glutMainLoop();
	return 0;
}
