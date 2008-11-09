LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g -o
GDB = -g -c

game: main.o
	g++ $(LDLIBS) main.o ball.o game

main.o: main.cpp ball.o
	g++ $(GDB) main.cpp

ball.o: ball.cpp ball.hpp
	g++ $(GDB) ball.cpp

object.o: object.cpp object.hpp
	g++ $(GDB) object.cpp

