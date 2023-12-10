#pragma once

namespace cli {

	/**
	 * Checks to see that a they character that's passed is paired to an executable command
	 * in the software.
	 * @param A char that's passed by reference
	 * @return A boolean where true represents a key that is paired to an existing command
	 */
	bool isValidCommandKey(char &key);

	/**
	 * Initialize the console by temporarily setting the terminals PS1 and PS2 env variables to an
	 * empty string, and then prints the main menu.
	 */
	void init();

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
