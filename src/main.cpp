#include "interface.h"
#include "operations.h"
#include <curses.h>

int main() {

	initscr();

	

	cli::printMainMenu();

	while (1) {

		switch(getch()) {
			case 113:
				Quit();
				break;
			case 104:
				Help();
				break;
		};

		refresh();
	}

	endwin();
	return 0;
}
