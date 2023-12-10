#include <ncurses.h>
#include <cstdlib>

#include "operations.h"
#include "interface.h"


void Quit::action() {

	endwin();
	exit(0);

};


std::string Quit::getHelpString() {

	return "";
};


void Help::action() {

	cli::printHelpMenu();

};
