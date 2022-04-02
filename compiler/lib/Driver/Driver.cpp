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
