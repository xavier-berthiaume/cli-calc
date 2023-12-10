#include <cstdlib>
#include <iostream>
#include <ncurses.h>

#include "interface.h"

bool cli::isValidCommandKey(char &key){

	return false;
}


void printCalculatorFrame() {

}


void cli::printMainMenu(){

	system("clear");
	printw("<-----  CLI CALCULATOR ----->");
	printw("\nWritten by Xavier Berthiaume circa 2023");
	printw("\n\n");

	printw("\n\tPress (h) for Help");
	printw("\n\tPress (q) to Quit");
	
}
