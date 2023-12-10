#include <curses.h>
#include <ncurses.h>
#include <string>

#include "interface.h"

bool cli::isValidCommandKey(char &key) {

	return false;
}


void printCenteredString(int y, std::string message) {
	
	int x;
	x = COLS/2;

	mvprintw(y, x-(message.length()/2), message.data());

}


void minimumWindowSizeWarning() {

	printCenteredString(1, "Your terminal window");
	printCenteredString(2, "doesn't meet the minimum");
	printCenteredString(3, "required size!");
	printCenteredString(5, "Some content might not");
	printCenteredString(6, "display as intended");

	printCenteredString(9, "PRESS ANY KEY TO CONTINUE");
	getch();

}


void cli::initInterface() {


	initscr();

	if (COLS < cli::MINIMUM_COLS)
		minimumWindowSizeWarning();
	else if (LINES < cli::MINIMUM_ROWS)
		minimumWindowSizeWarning();

	// Create the CalculatorInterface object for the
	// program to use
	CalculatorInterface::getInstance();

}


void cli::printMainMenu() {

	clear();
	
	int y;
	y = LINES/2;

	printCenteredString(y, "<----- CLI CALCULATOR ----->");
	printCenteredString(y+1, "Written by Xavier Berthiaume circa 2023");
	
	printCenteredString(y+5, "Press (h) for Help");
	printCenteredString(y+6, "Press (q) to Quit");
	
	CalculatorInterface::getInstance()->drawCalculatorInterface();
	
	refresh();
}

void cli::printHelpMenu() {

	clear();

	int y;
	y = LINES/2;

	printCenteredString(y, "<----- HELP MENU ----->");
	printCenteredString(y+1, "Press a for special effects");
	printCenteredString(y+2, "Press q to quit");

	printCenteredString(y+5, "PRESS ANY KEY TO CONTINUE");

	refresh();
}


CalculatorInterface *CalculatorInterface::instance = nullptr;


CalculatorInterface *CalculatorInterface::getInstance() {

	CalculatorInterface *instance = CalculatorInterface::instance;

	if(instance == nullptr) {
		
		instance = new CalculatorInterface();
		
		int start_x, start_y;

		start_x = COLS/2 - 25;
		start_y = LINES/2 + 8;
		instance->win = newwin(CalculatorInterface::HEIGHT, CalculatorInterface::WIDTH, start_y, start_x);
		refresh();

	}

	return instance;

}


WINDOW *CalculatorInterface::getWindow() {

	return this->win;
	
}


void CalculatorInterface::drawCalculatorInterface() {

	box(this->getWindow(), 0, 0);
	wrefresh(this->getWindow());
}
