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


bool validatePosition(unsigned int &position) {

	if(position < 8)
		return true;

	return false;

}

std::tuple<int, int> calculatePositionCoordinates(unsigned int &position) {

	// The top row will always be at y = 1
	int y = 1, x;

	x = 1 + position * 7;

	return std::make_tuple(y,x);
	
}


void CalculatorInterface::printZero(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printOne(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printTwo(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printThree(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printFour(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printFive(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printSix(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printSeven(unsigned int position) {
	
	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printEight(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


void CalculatorInterface::printNine(unsigned int position) {

	// Exit the function early if we're not printing
	// in a valid position
	if(!validatePosition(position))
		return;

	// Get the window we're printing in
	WINDOW *win = CalculatorInterface::getInstance()->getWindow();

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

	wrefresh(win);

}


WINDOW *CalculatorInterface::getWindow() {

	return this->win;
	
}


void CalculatorInterface::drawCalculatorInterface() {

	box(this->getWindow(), 0, 0);
	wrefresh(this->getWindow());
}
