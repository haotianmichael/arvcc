//===---------------------------------===//
//
// This file implements the Driver-related interfaces.
//
//===---------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc;

Compilation* Driver::BuildCompilation() {

	ParseArgStrings();
	Compilation* C = new Compilation(*this);

	return C;
}

int Driver::ExecuteCompilation(Compilation& C) {
	return 0;
}

void Driver::ParseArgStrings() {

	return;
}

bool Driver::HasCC1Tool() {

	auto FirstArg = std::find_if(Args.begin() + 1, Args.end(),
															 [](const char* A) { return A != nullptr; });
	return (FirstArg != Args.end() && !strcmp(*FirstArg, "-cc1"));
}
