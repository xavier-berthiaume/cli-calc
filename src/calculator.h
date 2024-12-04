#pragma once

#include "interface.h"
#include <curses.h>

class Calculator {

	int register1, register2, currentRegister;
	char operation;

	static Calculator *instance;
	CalculatorInterface *interface;

	/**
	 * Private constructor because of singleton implementation
	 */
	Calculator() = default;

public:
	/**
	 * The access function to get the singleton instance.
	 * If the instance has not yet been instantiated, then
	 * create it.
	 *
	 * @returns Calculator global instance.
	 */
	static Calculator *getInstance();

	/**
	 * Get the window of the interface. Implemented to be used with 
	 * wrefresh(WINDOW *)
	 *
	 * @return WINDOW The ncurses window associated to the 
	 * calculator's interface
	 */
	WINDOW *getWindow();

	/**
	 * Sets the operation that will be executed. Changes the register
	 * that's being worked on to register2.
	 *
	 * @param A char of the operator that will be used to calculate the 
	 * result of the expression.
	 * Accepted parameters are '+', '-', '/', '*', '%'
	 */
	void setOperation(char &operation);
	
	/**
	 * Bumps the value of a register with the integer that's passed.
	 * The integer value that's passed is appended in the single digits
	 * place, pushing all other already stored digits to the left.
	 *  
	 * @param value The integer value to add to the register.
	 */
	void bumpRegisterValue(unsigned int &value);

	/**
	 * Converts the sign of the value stored in the register.
	 */
	void negateRegister();

	/**
	 * Clears the value of register1 and register2, as well as the 
	 * operation that was set. Resets the currentRegister to register1.
	 */
	void clearRegisters();

	/**
	 * Uses the values stored in register1 and register2 to conduct
	 * operation on. Prints the result to the interface. 
	 * If the value of register2 or the operation has not
	 * been set yet, do nothing.
	 */
	void calculate();

	/**
	 * Displays the calculators interface
	 */
	void displayInterface();


};
