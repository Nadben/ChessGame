all:
		g++ -std=c++11 -g board.cpp player.cpp piece.cpp game.cpp skynet.cpp gameEngine.cpp database.cpp main.cpp  -o main.out
