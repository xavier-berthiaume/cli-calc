#include <cstdio>

#include "interface.h"

int main() {

	char key_pressed = {};

	cli::init();

	// Main function loop
	while(1) {

		// 1. Show main menu
		// 2. Wait for user input
		// 3. Check the command key
		// 3.1 If integer, it's written in 
		//     the calc and start from the top
		// 3.2 If valid char, execute that function
		//     and start from the top
		// 3.3 If nonvalid char, print help menu
		//     and start from the top

		cli::printMainMenu();

		key_pressed = getc(stdin);


	}
	return 0;
}
