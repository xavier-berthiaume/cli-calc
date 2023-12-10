#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <string>

#include "interface.h"

bool cli::isValidCommandKey(char &key){

	return false;
}


void printCalculatorFrame() {

}


void printCenteredString(int y, std::string message) {
	
	int x;
	x = COLS/2;

	mvprintw(y, x-(message.length()/2), message.data());

}


void cli::printMainMenu(){

	clear();
	
	int y;
	y = LINES/2;

	printCenteredString(y, "<----- CLI CALCULATOR ----->");
	printCenteredString(y+1, "Written by Xavier Berthiaume circa 2023");

	printCenteredString(y+5, "Press (h) for Help");
	printCenteredString(y+6, "Press (q) to Quit");
	
}

void cli::printHelpMenu(){

	clear();

	std::string message = {};
	int x,y;
	x = COLS/2;
	y = LINES/2;

	message = "<----- HELP MENU ----->";
	mvprintw(y, x-(message.length()/2), message.data());
	mvprintw(y+1,x+15, "Press a for special effects");
	mvprintw(y+2, x+15, "Press q to quit");

	mvprintw(y+5, x, "PRESS ANY KEY TO CONTINUE");

}
