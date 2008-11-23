LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g
GDB = -g -Wall -c

game: main.o
	g++ $(LDLIBS) main.o paddle.o destructible_block.o block.o ball.o graphic.o color.o image.o -o game

main.o: main.cpp ball.o destructible_block.o paddle.o
	g++ $(GDB) main.cpp

# compile various blocks
paddle.o: paddle.cpp paddle.h block.o color.o
	g++ $(GDB) paddle.cpp

destructible_block.o: destructible_block.cpp destructible_block.h block.o color.o
	g++ $(GDB) destructible_block.cpp

block.o: block.cpp block.h graphic.o
	g++ $(GDB) block.cpp

#compile ball
ball.o: ball.cpp ball.h graphic.o color.o
	g++ $(GDB) ball.cpp

#Where everything roots from
graphic.o: graphic.cpp graphic.h
	g++ $(GDB) graphic.cpp

color.o: color.cpp color.h
	g++ $(GDB) color.cpp

image.o: image.cpp image.h
	g++ $(GDB) image.cpp
