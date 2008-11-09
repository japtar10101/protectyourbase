#include "ball.h"

Ball::Ball() {
	x = 0;
	y = 0;
	x_move = 0.000001;
	y_move = 0.000001;
}

Ball::Ball( int x1, int y1 ) {
	x = x1;
	y = y1;
}

void Ball::draw_ball() {
	x += x_move;
	y += y_move;
	glColor3f( 1.0, 1.0, 1.0 );
	glBegin(GL_POLYGON);
	for( int index = 0; index < 360; ++index ) {
		float degInRad = index * DEGR_TO_RADIANS;
		float x_coord = cos( degInRad );
		x_coord = x_coord * RADIUS + x;
		float y_coord = sin( degInRad );
		y_coord = y_coord * RADIUS + y;
		glVertex2f( x_coord, y_coord );
	}
	glEnd();
	glutPostRedisplay();
}
