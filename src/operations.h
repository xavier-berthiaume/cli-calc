#pragma once

#include <string>


struct Quit {

	static const int key_ascii_code = 113;

	static void action();

	static std::string getHelpString();

};


struct Help {

	static const int key_ascii_code = 104;

	static void action();

	static std::string getHelpString();

};
