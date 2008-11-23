LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g
GDB = -g -Wall -c

game: main.o
	g++ $(LDLIBS) main.o block.o ball.o graphic.o -o game

main.o: main.cpp ball.o block.o
	g++ $(GDB) main.cpp

# compile various blocks
block.o: block.cpp block.h graphic.o
	g++ $(GDB) block.cpp

#compile ball
ball.o: ball.cpp ball.h graphic.o
	g++ $(GDB) ball.cpp

#Where everything roots from
graphic.o: graphic.cpp graphic.h
	g++ $(GDB) graphic.cpp

color.o: color.cpp color.h
	g++ $(GDB) color.cpp
