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

#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
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
	// Seed random number generator
	srand(time(NULL));

    int running = true;

	// Build square list and colors
	const char * square_names[] = {
		"a1","a2","a3","a4","a5","a6","a7","a8",
		"b1","b2","b3","b4","b5","b6","b7","b8",
		"c1","c2","c3","c4","c5","c6","c7","c8",
		"d1","d2","d3","d4","d5","d6","d7","d8",
		"e1","e2","e3","e4","e5","e6","e7","e8",
		"f1","f2","f3","f4","f5","f6","f7","f8",
		"g1","g2","g3","g4","g5","g6","g7","g8",
		"h1","h2","h3","h4","h5","h6","h7","h8"
	};
	const char square_colors[] = {
		'b','w','b','w','b','w','b','w',
		'w','b','w','b','w','b','w','b',
		'b','w','b','w','b','w','b','w',
		'w','b','w','b','w','b','w','b',
		'b','w','b','w','b','w','b','w',
		'w','b','w','b','w','b','w','b',
		'b','w','b','w','b','w','b','w',
		'w','b','w','b','w','b','w','b'
	};

	// Store the correct attempts
	int correct = 0;
	int total_attempts = 0;

    while(running) {
        clear();
		// Select square
		int r = rand() % 64;

		move(0,0);
		printw("Chess Vision Trainer");
		move(1,0);
		printw("--------------------");
		move(2,0);
		printw("Press 'q' to quit.");

		move(3,0);
		printw("Correct: %d", correct);
		move(4,0);
		printw("Total attempts: %d", total_attempts);
		move(5,0);
		printw("Percent correct: %.1f",
				(correct / (double)total_attempts) * 100);

		move(7,0);
		printw("Is the square (b)lack or (w)hite:");
		move(7, 34);
		printw(square_names[r]);

		// Get the selection
        int ch = getch();
        switch (ch) {
            case 'q': // Quit
                running = false;
                break;
			case 'w': // White
				total_attempts++;
				if (square_colors[r] == 'w') {
					correct++;
				}
				break;
			case 'b': // Black
				total_attempts++;
				if (square_colors[r] == 'b') {
					correct++;
				}
				break;
        }
        refresh();
    }

    // Must call to end ncurses
    endwin();
}
