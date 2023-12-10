#include <cstdlib>
#include <iostream>

#include "interface.h"

bool cli::isValidCommandKey(char &key){

	return false;
}


void cli::init(){

	const char *void_ps1 = "PS1";
	const char *void_ps2 = "PS2";
	unsetenv(void_ps1);
	unsetenv(void_ps2);

	system("clear");
}


void printCalculatorFrame() {

}


void cli::printMainMenu(){

	system("clear");
	std::cout << "<-----  CLI CALCULATOR ----->";
	std::cout << "\n\nWritten by Xavier Berthiaume circa 2023";
	std::cout << "\n\n\n\n";


	std::cout << "\n\tPress (h) for Help";
	std::cout << "\n\tPress (q) to Quit";
	
}
