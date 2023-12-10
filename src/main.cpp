#include "interface.h"
#include "operations.h"
#include <ncurses.h>

int main() {

	char pressed_key = {};

	initscr();


	while(1) {

		refresh();

		cli::printMainMenu();
		
		pressed_key = getch();

		switch(pressed_key) {
			case Quit::key_ascii_code: 
				Quit::action();
				break;
			case Help::key_ascii_code:
				Help::action();
				getch();
				break;
		};

	}

	return 0;
}
