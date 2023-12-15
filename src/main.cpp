#include "interface.h"
#include "calculator.h"
#include "operations.h"

#include <curses.h>
#include <ncurses.h>

int main() {

	char pressed_key = {};

	cli::initInterface();

	Calculator *calc = Calculator::getInstance();

	while(1) {

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
