/*
    Chess Vision Trailer - Train your chess vision ability.
    Copyright (C) 2019 Harold Freeman (haroldfreeman@protonmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <signal.h>
#include <ncurses.h>
#include <unistd.h>

void* resizeHandler(int);

int main(int argc, char *argv[]) {
    int max_y = 0, max_x = 0;

    signal(SIGWINCH, resizeHandler);

    // Setup ncurses
    initscr();
    // One character at a time
    cbreak();
    // Disable echo
    noecho();
    // Hide cursor
    curs_set(FALSE);
    // Capture special keys
    keypad(stdscr, TRUE);

    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    int running = 1;

    while(running) {
        clear();
        // Get current window x/y
        getmaxyx(stdscr, max_y, max_x);
        int ch = getch();
        switch (ch) {
            case KEY_BACKSPACE: /* user pressed backspace */
                running = 0;
                break;
            default:
                mvprintw(1, 1, ch);
        }
        refresh();
    }

    endwin();
}

void* resizeHandler(int sig) {
    int nh, nw;
    getmaxyx(stdscr, nh, nw);
}
