#include "interface.h"
#include "calculator.h"
#include "operations.h"

#include <ncurses.h>

int main() {

	char pressed_key = {};

	cli::initInterface();

	Calculator *calc = Calculator::getInstance();
	
	while(1) {

		cli::printMainMenu();	
		
		calc->displayInterface();

		wrefresh(calc->getWindow());
		refresh();

		pressed_key = getch();

		unsigned int bump_value = 10;
		char operation = '\0';
		
		switch(pressed_key) {
			case Quit::key_ascii_code: 
				Quit::action();
				break;
			case Help::key_ascii_code:
				Help::action();
				getch();
				break;
			case 48:
				bump_value = 0;
				break;
			case 49:
				bump_value = 1;
				break;
			case 50:
				bump_value = 2;
				break;
			case 51:
				bump_value = 3;
				break;
			case 52:
				bump_value = 4;
				break;
			case 53:
				bump_value = 5;
				break;
			case 54:
				bump_value = 6;
				break;
			case 55:
				bump_value = 7;
				break;
			case 56:
				bump_value = 8;
				break;
			case 57:
				bump_value = 9;
				break;
			case 110:
				calc->negateRegister();
				break;
			case 99:
				calc->clearRegisters();
				break;
			case 43:
				operation = '+';
				break;
			case 45:
				operation = '-';
				break;
			case 47:
				operation = '/';
				break;
			case 42:
				operation = '*';
				break;
			case 61:
				calc->calculate();
				break;
		};
		
		if(bump_value >= 0 && bump_value < 10)
			calc->bumpRegisterValue(bump_value);

		if(operation)
			calc->setOperation(operation);
	}

	return 0;
}
