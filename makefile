all: compile

compile: tetris.cpp
	g++ tetris.cpp Grid.cpp Tetramino.cpp -lncurses -o tetris
