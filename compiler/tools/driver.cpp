//===-- driver.cpp- arvcc Driver------------------------===//
//
//
// This is the entry point to arvcc driver; it provides interfaces
// for functionality of arvcc driver library.
//
//===----------------------------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc;

int main(int Argc, const char** Argv) {

	DiagnosticEngine             Diags;
	Driver                       TheDriver(Diags, Argv, Argc);
	std::unique_ptr<Compilation> C(TheDriver.BuildCompilation());
	int                          Res = 1;
	if (C) {
		Res = TheDriver.ExecuteCompilation(*C);
	}

	std::cout << "hello, my name is arvcc." << std::endl;
	return Res;
}
