#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "Grid.hpp"

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
    bool draw_tetramino(Grid &, int, int, WINDOW *);
    void move_down_tetramino(Grid &, WINDOW *);
    void move_right_tetramino(Grid &g, WINDOW *win);
    void move_left_tetramino(Grid &g, WINDOW *win);
    ~Tetramino() = default;
};

#endif