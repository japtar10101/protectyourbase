#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define RADIUS 0.05
#define DEGR_TO_RADIANS (3.14159/180);
class Ball {
	public:
	float x, y;
	float x_move, y_move;
	
	Ball();
	Ball( int x1, int y1 );
	
	void draw_ball();
};
