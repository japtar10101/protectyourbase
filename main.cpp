#include "ball.hpp"

/**** initialize variables ****/
static const int window_position_x = 400;
static const int window_position_y = 200;
static const int window_size_width = 700;
static const int window_size_height = 700;
static const int width = 1;
static const int height = 1;
static const char *window_title = "The Game!!!";
Ball ball;

//make the display function
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	ball.draw();
	glutPostRedisplay();
	glFlush(); 
}

//set the animations
void animation( int value ) {
	if( ball.right() > width || ball.left() < width * (-1) ) {
		ball.bounce_horizontally();
		ball.increase_velocity();
	}
	if( ball.top() > height || ball.bottom() < height * (-1) ) {
		ball.bounce_vertically();
		ball.increase_velocity();
	}
	ball.animate();
	display();
	glutTimerFunc( 1, animation, 0 );
}

int main( int argc, char** argv ) {
	ball = Ball();
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition( window_position_x,
		window_position_y );
    glutInitWindowSize( window_size_width,
		window_size_height );
	glutCreateWindow( window_title );
	glutDisplayFunc( display );
	glutTimerFunc( 1, animation, 0 );
	glutMainLoop();
	return 0;
}
