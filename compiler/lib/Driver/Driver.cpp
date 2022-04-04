//===---------------------------------===//
//
// This file implements the Driver-related interfaces.
//
//===---------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc;

Compilation* Driver::BuildCompilation() {

	bool ContainsError;
	CLOptions = std::make_unique<opt::InputArgList>(
			ParseArgStrings(ContainsError));
	Compilation* C = new Compilation(*this);

	return C;
}

int Driver::ExecuteCompilation(Compilation& C) {
	return 0;
}

opt::InputArgList Driver::ParseArgStrings(bool ContainsError) {

}

bool Driver::HasCC1Tool() {

	auto FirstArg = std::find_if(
			Args.begin() + 1, Args.end(), [](const char* A) { return A != nullptr; });
	return (FirstArg != Args.end() && !strcmp(*FirstArg, "-cc1"));
}