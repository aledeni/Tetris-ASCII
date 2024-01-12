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

bool Tetramino::draw_tetramino(Grid &g, int y, int x, WINDOW *win) {
    char (*m)[COLS] = g.get_grid();
    this->start_x = x;
    this->start_y = y;
    if(tetramino == 0) {
        if(x > END_POINT-3) {
            x = END_POINT-3;
            this->start_x = x;
        }
        if(m[0][x] == '[' && m[0][x+1] == ']' && m[0][x+2] == '[' && m[0][x+3] == ']') {
            // Room finished
            return false;
        }
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
    }
    else if(tetramino == 1) {
        if(x > END_POINT-7) {
            x = END_POINT-7;
            this->start_x = x;
        }
        if(m[0][x] == '[' && m[0][x+1] == ']' && m[0][x+2] == '[' && m[0][x+3] == ']' &&
           m[0][4] == '[' && m[0][x+5] == ']' && m[0][x+6] == '[' && m[0][x+7] == ']') {
            // Room finished
            return false;
        }
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
    }
    else if(tetramino == 2) {
        if(x > END_POINT-3) {
            x = END_POINT-3;
            this->start_x = x;
        }
        if(m[0][x] == '[' && m[0][x+1] == ']' && m[0][x+2] == '[' && m[0][x+3] == ']') {
            // Room finished
            return false;
        }
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x -= 3;
        y++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
        x++;
        m[y][x] = '[';
        x++;
        m[y][x] = ']';
    }
    g.draw_grid(win, 0, 0);
    return true;
}

void Tetramino::move_down_tetramino(Grid &g, WINDOW *win) {
    char (*m)[COLS] = g.get_grid();
    int x = {start_x}, y {start_y};
    {
        std::lock_guard<std::mutex> lock(mutex);
        if(tetramino == 0) {
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x -= 3;
            y++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
            x++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
        }
        else if(tetramino == 1) {
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            y++;
            x -= 7;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
            x++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
            x++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
            x++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
        }
        else if(tetramino == 2) {
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x++;
            m[y][x] = '.';
            x -= 3;
            y += 2;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
            x++;
            m[y][x] = '[';
            x++;
            m[y][x] = ']';
        }
        start_y++;
        g.draw_grid(win, 0, 0);
    }
}

void Tetramino::move_right_tetramino(Grid &g, WINDOW *win) {
    char (*m)[COLS] = g.get_grid();
    int x = {start_x}, y {start_y};
    {
        std::lock_guard<std::mutex> lock(mutex);
        if(tetramino == 0) {
            if(m[y][x+4] == '.') {
                m[y][x] = '.';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y][x+3] = '[';
                m[y][x+4] = ']';
            }
            else return;
        }
        else if(tetramino == 1) {
            if(m[y][x+8] == '.') {
                m[y][x] = '.';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y][x+3] = '[';
                m[y][x+4] = ']';
                m[y][x+5] = '[';
                m[y][x+6] = ']';
                m[y][x+7] = '[';
                m[y][x+8] = ']';
            }
            else return;
        }
        else if(tetramino == 2) {
            if(m[y][x+4] == '.' && m[y+1][x+4] == '.') {
                m[y][x] = '.';
                m[y+1][x] = '.';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y][x+3] = '[';
                m[y][x+4] = ']';
                m[y+1][x+1] = '[';
                m[y+1][x+2] = ']';
                m[y+1][x+3] = '[';
                m[y+1][x+4] = ']';
            }
            else return;
        }
        start_x++;
        g.draw_grid(win, 0, 0);
    }
}

void Tetramino::move_left_tetramino(Grid &g, WINDOW *win) {
    char (*m)[COLS] = g.get_grid();
    int x = {start_x}, y {start_y};
    {
        std::lock_guard<std::mutex> lock(mutex);
        if(tetramino == 0) {
            if(m[y][x-1] == '.') {
                m[y][x-1] = '[';
                m[y][x] = ']';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y][x+3] = '.';
            }
            else return;
        }
        else if(tetramino == 1) {
            if(m[y][x-1] == '.') {
                m[y][x-1] = '[';
                m[y][x] = ']';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y][x+3] = '[';
                m[y][x+4] = ']';
                m[y][x+5] = '[';
                m[y][x+6] = ']';
                m[y][x+7] = '.';
            }
            else return;
        }
        else if(tetramino == 2) {
            if(m[y][x-1] == '.' && m[y+1][x-1] == '.') {
                m[y][x-1] = '[';
                m[y][x] = ']';
                m[y][x+1] = '[';
                m[y][x+2] = ']';
                m[y+1][x-1] = '[';
                m[y+1][x] = ']';
                m[y+1][x+1] = '[';
                m[y+1][x+2] = ']';
                m[y][x+3] = '.';
                m[y+1][x+3] = '.';
            }
            else return;
        }
        start_x--;
        g.draw_grid(win, 0, 0);
    }
}

Tetramino& Tetramino::operator=(const Tetramino &other) {
    if(this != &other) {
        std::lock_guard<std::mutex> lock(mutex);
        tetramino = other.tetramino;
        start_x = other.start_x;
        start_y = other.start_y;
    }
    return *this;
}