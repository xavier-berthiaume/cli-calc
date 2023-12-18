#include "interface.h"
#include "calculator.h"
#include <ncurses.h>

Calculator *Calculator::instance = nullptr;

Calculator *Calculator::getInstance() {

	Calculator *instance = Calculator::instance;

	if(instance == nullptr) {

		instance = new Calculator();
		instance->currentRegister = 1;
		instance->operation = '\0';
		instance->interface = new CalculatorInterface();
		instance->interface->printNumber(0);
	}

	return instance;

}


WINDOW *Calculator::getWindow() {

	return this->interface->getWindow();

}


void Calculator::setOperation(char &operation) {

	this->operation = operation;
	this->currentRegister = 2;
	this->interface->printNumber(register2);

}


void Calculator::bumpRegisterValue(unsigned int &value) {

	int new_value = {};

	switch(currentRegister) {
		case 1:
			if(register1*10<9999999 && register1*10>-999999) {
				register1 = register1*10 + value;
				new_value = register1;
			}
			break;
		case 2:
			if(register2*10<9999999 && register1*10>-999999) {
				register2 = register2*10 + value;
				new_value = register2;
			}
			break;
	}
	
	this->interface->printNumber(new_value);

}


void Calculator::negateRegister() {

	int new_value = {};

	switch(currentRegister) {
		case 1:
			if(register1*-1<9999999 && register1*-1>-999999) {
				register1 = register1*-1;
				new_value = register1;
			}
			break;
		case 2:
			if(register2*-1<9999999 && register2*-1>-999999) {
				register2 = register2*-1;
				new_value = register2;
			}
			break;
	}

	this->interface->printNumber(new_value);

}


void Calculator::clearRegisters() {

	register1 = 0;
	register2 = 0;
	operation = '\0';
	currentRegister = 1;

	this->interface->printNumber(register1);
}


void Calculator::calculate() {

	if(operation == '\0')
		return;

	int result = {};

	switch(operation) {
		case '+':
			result = register1 + register2;
			break;
		case '-':
			result = register1 - register2;
			break;
		case '/':
			result = register1 / register2;
			break;
		case '*':
			result = register1 * register2;
			break;
	}

	this->interface->printNumber(result);

}

void Calculator::displayInterface() {

	int register_value;

	this->interface->drawCalculatorInterface();
	switch(currentRegister) {
		case 1:
			register_value = register1;
			break;
		case 2:
			register_value = register2;
			break;
	}

	this->interface->printNumber(register_value);

}
