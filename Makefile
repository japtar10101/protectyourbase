LDLIBS = -lglut -lGL -lGLU -lXmu -lX11 -lm -L/usr/X11R6/lib -g
GDB = -g -Wall -c
GAMELIBS = game.o player.o base.o paddle.o destructible_block.o block.o ball.o graphic.o mouse.o control.o color.o
MENULIBS = menu.o

################ link everything ####################

#compiles every executable
all: ProtectYourBase game menu

menu: test_menu.o
	g++ $(LDLIBS) test_menu.o $(MENULIBS) $(GAMELIBS) -o menu

game: test_game.o
	g++ $(LDLIBS) test_game.o $(GAMELIBS) -o game

ProtectYourBase: main.o
	g++ $(LDLIBS) main.o protect_your_base.o $(MENULIBS) $(GAMELIBS) -o ProtectYourBase

################ compile files with main ####################

#compile main
main.o: main.cpp protect_your_base.o
	g++ $(GDB) main.cpp

#compile menu components
test_menu.o: test_menu.cpp menu.o
	g++ $(GDB) test_menu.cpp

#compile game components
test_game.o: test_game.cpp game.o
	g++ $(GDB) test_game.cpp

################ compile ProtectYourBase ####################

protect_your_base.o: protect_your_base.cpp protect_your_base.h game.o menu.o
	g++ $(GDB) protect_your_base.cpp

################ compile menu element ####################

menu.o: menu.cpp menu.h game.o mouse.o
	g++ $(GDB) menu.cpp

################ compile game elements ####################

#compile game classes that puts many things together
game.o: game.cpp game.h player.o
	g++ $(GDB) game.cpp

player.o: player.cpp player.h base.o
	g++ $(GDB) player.cpp

base.o: base.cpp base.h paddle.o destructible_block.o control.o
	g++ $(GDB) base.cpp

#compile various blocks
paddle.o: paddle.cpp paddle.h block.o color.o
	g++ $(GDB) paddle.cpp

destructible_block.o: destructible_block.cpp destructible_block.h block.o color.o
	g++ $(GDB) destructible_block.cpp

############### compile basic graphics ####################

#compile basic block
block.o: block.cpp block.h graphic.o ball.o mouse.o
	g++ $(GDB) block.cpp

#compile ball
ball.o: ball.cpp ball.h graphic.o color.o
	g++ $(GDB) ball.cpp

#compile base graphics class
graphic.o: graphic.cpp graphic.h global.h
	g++ $(GDB) graphic.cpp

################ compile root elements ####################

mouse.o: mouse.cpp mouse.h global.h
	g++ $(GDB) mouse.cpp

control.o: control.cpp control.h global.h
	g++ $(GDB) control.cpp

color.o: color.cpp color.h
	g++ $(GDB) color.cpp

# A program I considered...
#image.o: image.cpp image.h
#	g++ $(GDB) image.cpp

