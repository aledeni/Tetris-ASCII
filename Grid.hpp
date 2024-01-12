#ifndef GRID_HPP
#define GRID_HPP

#include <ncurses.h>

#define ROWS 27 // 25 + 2
#define COLS 24 // 20 + 4

class Grid {
private:
    char grid[ROWS][COLS];
    void delete_lines(WINDOW *, int);

public:
    Grid();
    char (*get_grid())[COLS];
    void draw_grid(WINDOW *, int, int);
    void check_grid(WINDOW *);
    ~Grid() = default;
};

#endif