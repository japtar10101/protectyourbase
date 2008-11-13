LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g
GDB = -g -c

game: main.o
	g++ $(LDLIBS) main.o block.o ball.o graphic.o -o game

main.o: main.cpp ball.o block.o
	g++ $(GDB) main.cpp

# compile various blocks
block.o: block.cpp block.hpp graphic.o
	g++ $(GDB) block.cpp

#compile ball
ball.o: ball.cpp ball.hpp graphic.o
	g++ $(GDB) ball.cpp

#Where everything roots from
graphic.o: graphic.cpp graphic.hpp
	g++ $(GDB) graphic.cpp

