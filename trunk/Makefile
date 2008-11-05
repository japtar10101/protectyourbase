LDLIBS = -lglut -lGL -lGLU -lXmu -lX11  -lm -L/usr/X11R6/lib

game: main.o
	g++ $(LDLIBS) -g main.o ball.o -o game

main.o: main.cpp ball.o
	g++ -g -c main.cpp

ball.o: ball.cpp ball.h
	g++ -g -c ball.cpp
