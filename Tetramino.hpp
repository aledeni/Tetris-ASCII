#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#define START_POINT 2
#define END_POINT 21

class Tetramino {
private:
    int tetramino; // 0, 1, 2
    int start_x;
    int start_y;

public:
    Tetramino();
    int get_tetramino();
    int get_start_x();
    int get_start_y();
    void draw_tetramino(WINDOW *, int, int);
    void move_tetramino(WINDOW *);
    ~Tetramino() = default;
};

#endif