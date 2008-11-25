LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g
GDB = -g -Wall -c

game: main.o
	g++ $(LDLIBS) main.o game.o player.o base.o paddle.o destructible_block.o block.o ball.o graphic.o control.o color.o -o game

main.o: main.cpp game.o
	g++ $(GDB) main.cpp

# compile classes that puts many things together
game.o: game.cpp game.h player.o
	g++ $(GDB) game.cpp

player.o: player.cpp player.h base.o
	g++ $(GDB) player.cpp

base.o: base.cpp base.h paddle.o destructible_block.o control.o
	g++ $(GDB) base.cpp

# compile various blocks
paddle.o: paddle.cpp paddle.h block.o color.o
	g++ $(GDB) paddle.cpp

destructible_block.o: destructible_block.cpp destructible_block.h block.o color.o
	g++ $(GDB) destructible_block.cpp

block.o: block.cpp block.h graphic.o ball.o
	g++ $(GDB) block.cpp

#compile ball
ball.o: ball.cpp ball.h graphic.o color.o
	g++ $(GDB) ball.cpp

#Where everything roots from
graphic.o: graphic.cpp graphic.h global.h
	g++ $(GDB) graphic.cpp

control.o: control.cpp control.h global.h
	g++ $(GDB) control.cpp

color.o: color.cpp color.h
	g++ $(GDB) color.cpp

# A program I considered...
#image.o: image.cpp image.h
#	g++ $(GDB) image.cpp

