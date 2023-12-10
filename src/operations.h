#pragma once

#include <string>


struct Quit {

	static const char key = 'q';

	static void action();

	static std::string getHelpString();

};


struct Help {

	static const char key = 'h';

	static void action();

	static std::string getHelpString();

};
