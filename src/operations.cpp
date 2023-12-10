#include <cstdlib>

#include "./operations.h"

void Quit::action() {

	exit(0);

};


std::string Quit::getHelpString() {

	return "";
};
