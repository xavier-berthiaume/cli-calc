#pragma once

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
