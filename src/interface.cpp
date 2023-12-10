#include <iostream>
#include <ncurses.h>

#include "interface.h"

bool cli::isValidCommandKey(char &key){

	return false;
}


void printCalculatorFrame() {

}


void cli::printMainMenu(){

	clear();
	
	int x,y;
	x = 50;
	y = 25;

	mvprintw(y,x,"<-----  CLI CALCULATOR ----->");
	mvprintw(y+1,x,"Written by Xavier Berthiaume circa 2023");

	move(y+3,x+15);
	printw("\tPress (h) for Help");
	move(y+4,x+15);
	printw("\tPress (q) to Quit");
	
}

void cli::printHelpMenu(){

	clear();

	int x,y;
	x = 50;
	y = 10;

	mvprintw(y, x,"<----- HELP MENU ----->");
	mvprintw(y+1,x+15, "Press a for special effects");
	mvprintw(y+2, x+15, "Press q to quit");

	mvprintw(y+5, x, "PRESS ANY KEY TO CONTINUE");

}
