#include <curses.h>
#include <ncurses.h>
#include <string>
#include <tuple>

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

}


void cli::printMainMenu() {

	clear();
	
	int y;
	y = 2;

	printCenteredString(y, "<----- CLI CALCULATOR ----->");
	printCenteredString(y+1, "Written by Xavier Berthiaume circa 2023");
	
	printCenteredString(y+5, "Press (h) for Help");
	printCenteredString(y+6, "Press (q) to Quit");

}

void cli::printHelpMenu() {

	clear();

	int y;
	y = 2;

	printCenteredString(y, "<----- HELP MENU ----->");
	printCenteredString(y+1, "Press a for special effects");
	printCenteredString(y+2, "Press q to quit");

	printCenteredString(y+5, "PRESS ANY KEY TO CONTINUE");

}


CalculatorInterface::CalculatorInterface() {

	int start_x, start_y;

	start_x = COLS/2 - CalculatorInterface::WIDTH/2;
	start_y = 10;
	this->win = newwin(CalculatorInterface::HEIGHT, CalculatorInterface::WIDTH, start_y, start_x);

}


bool validatePosition(unsigned int &position) {

	if(position < 7)
		return true;

	return false;

}


std::tuple<int, int> calculatePositionCoordinates(unsigned int &position) {

	// The top row will always be at y = 1
	int y = 1, x;

	x = 1 + position * 7;

	return std::make_tuple(y,x);

}


void CalculatorInterface::printNegative(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   "      ");
	mvwprintw(win, y+1, x, "      ");
	mvwprintw(win, y+2, x, "------");
	mvwprintw(win, y+3, x, "      ");
	mvwprintw(win, y+4, x, "      ");
	
}

void CalculatorInterface::printZero(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 0000 ");
	mvwprintw(win, y+1, x, "00  00");
	mvwprintw(win, y+2, x, "00  00");
	mvwprintw(win, y+3, x, "00  00");
	mvwprintw(win, y+4, x, " 0000 ");

}


void CalculatorInterface::printOne(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   "1111  ");
	mvwprintw(win, y+1, x, "  11  ");
	mvwprintw(win, y+2, x, "  11  ");
	mvwprintw(win, y+3, x, "  11  ");
	mvwprintw(win, y+4, x, "111111");

}


void CalculatorInterface::printTwo(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 2222 ");
	mvwprintw(win, y+1, x, "22  22");
	mvwprintw(win, y+2, x, "   22 ");
	mvwprintw(win, y+3, x, "  22  ");
	mvwprintw(win, y+4, x, "222222");

}


void CalculatorInterface::printThree(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 3333 ");
	mvwprintw(win, y+1, x, "33  33");
	mvwprintw(win, y+2, x, "   333");
	mvwprintw(win, y+3, x, "33  33");
	mvwprintw(win, y+4, x, " 3333 ");

}


void CalculatorInterface::printFour(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   "44  44");
	mvwprintw(win, y+1, x, "44  44");
	mvwprintw(win, y+2, x, "444444");
	mvwprintw(win, y+3, x, "    44");
	mvwprintw(win, y+4, x, "    44");

}


void CalculatorInterface::printFive(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   "555555");
	mvwprintw(win, y+1, x, "55    ");
	mvwprintw(win, y+2, x, "55555 ");
	mvwprintw(win, y+3, x, "    55");
	mvwprintw(win, y+4, x, "55555 ");

}


void CalculatorInterface::printSix(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 6666 ");
	mvwprintw(win, y+1, x, "66    ");
	mvwprintw(win, y+2, x, "66666 ");
	mvwprintw(win, y+3, x, "66  66");
	mvwprintw(win, y+4, x, " 6666 ");

}


void CalculatorInterface::printSeven(unsigned int position) {
	
	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   "777777");
	mvwprintw(win, y+1, x, "   77 ");
	mvwprintw(win, y+2, x, "  77  ");
	mvwprintw(win, y+3, x, " 77   ");
	mvwprintw(win, y+4, x, "77    ");

}


void CalculatorInterface::printEight(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 8888 ");
	mvwprintw(win, y+1, x, "88  88");
	mvwprintw(win, y+2, x, " 8888 ");
	mvwprintw(win, y+3, x, "88  88");
	mvwprintw(win, y+4, x, " 8888 ");

}


void CalculatorInterface::printNine(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = this->getWindow();

	std::tuple<int, int> coordinates = calculatePositionCoordinates(position);

	int y = std::get<0>(coordinates), x = std::get<1>(coordinates);

	// Special thanks to Yuan Qing Lim for sharing some ascii art of 
	// each digit on github gists.
	//
	// https://gist.github.com/yuanqing/ffa2244bd134f911d365
	// https://yuanqing.sg
	mvwprintw(win, y, x,   " 9999 ");
	mvwprintw(win, y+1, x, "99  99");
	mvwprintw(win, y+2, x, " 99999");
	mvwprintw(win, y+3, x, "    99");
	mvwprintw(win, y+4, x, " 9999 ");

}


WINDOW *CalculatorInterface::getWindow() {

	return this->win;
	
}


void CalculatorInterface::drawCalculatorInterface() {

	box(this->getWindow(), 0, 0);
	wrefresh(this->getWindow());
	refresh();

}


void CalculatorInterface::printNumber(int value_to_print) {

	std::string converted_number = std::to_string(value_to_print);
	int position = {0};

	for(char &digit : converted_number) {
		
		switch(digit) {
			case 48:
				this->printZero(position);
				break;
			case 49:
				this->printOne(position);
				break;
			case 50:
				this->printTwo(position);
				break;
			case 51:
				this->printThree(position);
				break;
			case 52:
				this->printFour(position);
				break;
			case 53:
				this->printFive(position);
				break;
			case 54:
				this->printSix(position);
				break;
			case 55:
				this->printSeven(position);
				break;
			case 56:
				this->printEight(position);
				break;
			case 57:
				this->printNine(position);
				break;
			case 45:
				this->printNegative(position);
				break;
		};

		position++;

	}

	this->drawCalculatorInterface();
}
