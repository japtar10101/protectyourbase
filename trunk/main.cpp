#include "ball.h"

static const int window_position_x = 400;
static const int window_position_y = 200;
static const int window_size_width = 700;
static const int window_size_height = 700;
static const char *window_title = "The Game!!!";
static Ball ball;

//make the display function
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	ball.draw_ball();
	glFlush(); 
}

int main( int argc, char** argv ) {
	ball = Ball();
	printf( "%f, %f\n", ball.x, ball.y );
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition( window_position_x,
		window_position_y );
    glutInitWindowSize( window_size_width,
		window_size_height );
	glutCreateWindow( window_title );
	glutDisplayFunc( display );
	glutMainLoop();
	return 0;
}
