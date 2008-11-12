#include "ball.hpp"

/**** initialize variables ****/
static const int width = 1, height = 1,
	window_position_x = 400, window_position_y = 200;
static const char *window_title = "The Game!!!";
GLsizei window_size_width = 700, window_size_height = 700;
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
	/*
	if( ball.right() > width || ball.left() < width * (-1) ) {
		ball.bounce_horizontally();
		ball.increase_velocity();
	}
	if( ball.top() > height || ball.bottom() < height * (-1) ) {
		ball.bounce_vertically();
		ball.increase_velocity();
	}
	ball.animate();
	*/
	display();
	glutTimerFunc( 1, animation, 0 );
}

/* reshaping routine called whenever window is resized or moved */
void resize_window( GLsizei w, GLsizei h ) {
	//adjust clipping box
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, (GLdouble) w, 0.0, (GLdouble) h, -1.0, 1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	//adjust viewport and clear
	glViewport( 0, 0, w, h );
	glClearColor( 0.0, 0.0, 0.0, 1.0);
	glClear( GL_COLOR_BUFFER_BIT );
	display();
	glFlush();
	//set global size for use by drawing routine
	window_size_width = w;
	window_size_height = h;
}

void initialize_window() {
	/* Pick 2D clipping window to match size of X window. This choice
	avoids having to scale object coordinates each time window is
	resized. */
	glViewport( 0, 0, window_size_width, window_size_height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, (GLdouble) window_size_width , 0.0,
		(GLdouble) window_size_height, -1.0, 1.0 );
	/* set clear color to black and clear window */
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glClear( GL_COLOR_BUFFER_BIT );
	glFlush();
}

int main( int argc, char** argv ) {
	ball = Ball();
	//basic setup
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
	//window position and size
	glutInitWindowPosition( window_position_x,
		window_position_y );
    glutInitWindowSize( window_size_width,
		window_size_height );
	glutCreateWindow( window_title );
	//setup functions
	glutDisplayFunc( display );
	glutTimerFunc( 1, animation, 0 );
	initialize_window();
	glutReshapeFunc( resize_window );
	//go! main loop!
	glutMainLoop();
	return 0;
}
