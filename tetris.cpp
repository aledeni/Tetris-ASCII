#include <ncurses.h>
#include <chrono>
#include <thread>
#include <future>
#include "Grid.hpp"
#include "Tetramino.hpp"

void update_time(int &elapsed_seconds, bool &exit_flag) {
    auto start_time = std::chrono::steady_clock::now();
    while (!exit_flag) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
        if (elapsed_time > elapsed_seconds) {
            elapsed_seconds = static_cast<int>(elapsed_time);
            mvprintw(6, 5, "TIME: %02d:%02d", elapsed_seconds / 60, elapsed_seconds % 60);
            refresh();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int gen_random_number(int min, int max) {
    // Returns a random integer between min and max (both inclusive)
    return rand()%(max-min+1)+min;
}

bool check_collision(Grid &g, Tetramino &t) {
    bool collision = false;
    int tipo {t.get_tetramino()}, x {t.get_start_x()}, y {t.get_start_y()};
    char (*m)[COLS] = g.get_grid();
    if(tipo == 0) {
        for(int i = x; i <= x+3; i++) {
            if(m[y+1][i] == '[' || m[y+1][i] == ']' || m[y+1][i] == '*') {
                collision = true;
            }
        }
    }
    else if(tipo == 1) {
        for(int i = x; i <= x+7; i++) {
            if(m[y+1][i] == '[' || m[y+1][i] == ']' || m[y+1][i] == '*') {
                collision = true;
            }
        }
    }
    else if(tipo == 2) {
        for(int i = x; i <= x+3; i++) {
            if(m[y+2][i] == '[' || m[y+2][i] == ']' || m[y+2][i] == '*') {
                collision = true;
            }
        }
    }
    return collision;
}

int main(int argc, char *argv[]) {
    /* NCURSES START */
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(0);
    nodelay(stdscr, true);

    // Variables
    srand(time(0));
    int height {30}, width {30}, start_y {2}, start_x {30};
    int full_lines {0}, score {0}, elapsed_seconds {0};
    int input_ch;
    bool end_game = false;

    // Score and time
    mvprintw(2, 5, "FULL LINES: %d", full_lines);
    mvprintw(4, 5, "SCORE: %d", score);
    mvprintw(6, 5, "TIME: 00:00");
    auto time_future = std::async(std::launch::async, update_time, std::ref(elapsed_seconds), std::ref(end_game));

    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();
    box(win, 0, 0);
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    Grid g {};
    g.draw_grid(win, 0, 0);
    
    // Game
    move(0, 0);
    Tetramino t;
    while(!end_game) {
        t = Tetramino();
        if(t.draw_tetramino(g, 0, gen_random_number(START_POINT, END_POINT), win)) {
            while(!check_collision(g, t)) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                input_ch = getch();
                switch (input_ch) {
                case KEY_RIGHT:
                    t.move_right_tetramino(g, win);
                    break;
                case KEY_LEFT:
                    t.move_left_tetramino(g, win);
                    break;
                default:
                    t.move_down_tetramino(g, win);
                    break;
                }
            }
        }
        else {
            end_game = true;
        }
    }

    mvprintw(35, 5, "GAME OVER, press any key to exit...");
    time_future.get();
    nodelay(stdscr, false);
    getch();
    endwin();
    /* NCURSES END */
}