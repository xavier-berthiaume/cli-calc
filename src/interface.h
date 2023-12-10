#pragma once

#include <ncurses.h>

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
	static const int WIDTH = 50, HEIGHT = 16;

	WINDOW *win;

	CalculatorInterface() = default;

public:
	
	static CalculatorInterface *getInstance();

	WINDOW *getWindow();

	/**
	 * Draws out the calculators borders as a box. The size of the box is that
	 * defined by WIDTH and HEIGHT.
	 *
	 * The position of the box is roughly a little below the vertical center.
	 * It horizontally centers.
	 */
	void drawCalculatorInterface();
};
