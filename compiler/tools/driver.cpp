//===-- driver.cpp- arvcc Driver------------------------===//
//
//
// This is the entry point to arvcc driver; it provides interfaces
// for functionality of arvcc driver library.
//
//===----------------------------------------------------===//

#include "Driver/Driver.h"

using namespace arvcc;
int main(int Argc, const char** Argv) {
	Driver TheDriver;
	int    Res = 1;

	std::cout << "hello, my name is arvcc." << std::endl;
	return Res;
}
