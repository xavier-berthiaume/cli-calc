#pragma once

#include <ncurses.h>
#include <string>

namespace cli {

	// Set the minimum terminal size for the application to run properly
	const int MINIMUM_COLS = 50, MINIMUM_ROWS = 30;
	
	/**
	 * Checks to see that a they character that's passed is paired to an executable command
	 * in the software.
	 * @param A char that's passed by reference
	 * @return A boolean where true represents a key that is paired to an existing command
	 */
	bool isValidCommandKey(char &key);

	/**
	 * Initializes ncurses and validates that the terminal is of the minimum required size.
	 * If not, prints a warning message to the user that they need to expand their window.
	 */
	void initInterface();

	/**
	 * Clears the screen, then prints the main menu over multiple lines.
	 */
	void printMainMenu();

	/**
	 * Clears the screen, then prints the help menu over multiple lines.
	 */
	void printHelpMenu();

	/**
	* Clears the screen, then prints an acknowledgment to the developper.
	*/
	void printCreditScreen();

};

/**
 * Singleton implementation of the consoles calculator interface.
 */
class CalculatorInterface {

	static CalculatorInterface *instance;
	static const int WIDTH = 50, HEIGHT = 10;

	WINDOW *win;

	CalculatorInterface() = default;

	/**
	 * Below are a collection of functions that print to the calculator
	 * interface the given number in ascii art.
	 *
	 * Each number ascii art has a width of 6, with a height of 5. The 
	 * CalculatorInterface has a window of size of WIDTH x HEIGHT, therefore
	 * a maximum of 7 digits can be displayed at once (considering a padding
	 * width of 1 between numbers and the borders)
	 *
	 * @param position Takes in an unsigned integer to know where on the
	 * calculator interface the number will be printed. Positions are from LEFT
	 * to RIGHT and start at 0.
	 */
	void printNegative(unsigned int position);
	void printZero(unsigned int position);
	void printOne(unsigned int position);
	void printTwo(unsigned int position);
	void printThree(unsigned int position);
	void printFour(unsigned int position);
	void printFive(unsigned int position);
	void printSix(unsigned int position);
	void printSeven(unsigned int position);
	void printEight(unsigned int position);
	void printNine(unsigned int position);

public:

	/**
	 * Static function that acts as both the initalizer for the global 
	 * CalculatorInterface singleton, and as a means to fetch that instance.
	 */
	static CalculatorInterface *getInstance();

	/**
	 * Getter function for the win member variable.
	 */
	WINDOW *getWindow();

	/**
	 * Draws out the calculators borders as a box. The size of the box is that
	 * defined by WIDTH and HEIGHT.
	 *
	 * The position of the box is roughly a little below the vertical center.
	 * It horizontally centers.
	 */
	void drawCalculatorInterface();
	
	/**
	 * Converts the passed int to ascii art and prints it to the calculator
	 * interface.
	 */
	void printNumber(int value_to_print);
};
