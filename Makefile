LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g -o
GDB = -g -c

game: main.o
	g++ $(LDLIBS) main.o ball.o graphic.o game

main.o: main.cpp ball.o
	g++ $(GDB) main.cpp

ball.o: ball.cpp ball.hpp graphic.o
	g++ $(GDB) ball.cpp

graphic.o: graphic.cpp graphic.hpp
	g++ $(GDB) graphic.cpp

