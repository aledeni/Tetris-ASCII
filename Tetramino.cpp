#include "Tetramino.hpp"

Tetramino::Tetramino() {
    tetramino = rand() % 3;
}

int Tetramino::get_tetramino() {
    return tetramino;
}

int Tetramino::get_start_x() {
    return start_x;
}

int Tetramino::get_start_y() {
    return start_y;
}

void Tetramino::draw_tetramino(WINDOW *win, int y, int x) {
    this->start_x = x;
    this->start_y = y;
    if(tetramino == 0) {
        if(x > END_POINT-3) {
            x = END_POINT-3;
            this->start_x = x;
        }
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    else if(tetramino == 1) {
        if(x > END_POINT-7) {
            x = END_POINT-7;
            this->start_x = x;
        }
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    else if(tetramino == 2) {
        if(x > END_POINT-3) {
            x = END_POINT-3;
            this->start_x = x;
        }
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x -= 3;
        y++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    wrefresh(win);
}

void Tetramino::move_tetramino(WINDOW *win) {
    int x = {start_x}, y {start_y};
    if(tetramino == 0) {
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x -= 3;
        y++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    else if(tetramino == 1) {
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        y++;
        x -= 7;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    else if(tetramino == 2) {
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x++;
        mvwaddch(win, y, x, '.');
        x -= 3;
        y += 2;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
        x++;
        mvwaddch(win, y, x, '[');
        x++;
        mvwaddch(win, y, x, ']');
    }
    this->start_y++;
    wrefresh(win);
}