#ifndef ARVCC_DRIVER_H
#define ARVCC_DRIVER_H

#include "Diag/Diagnostic.h"

namespace arvcc {

class Driver {

private:
	// The path the driver executable was invoked
	// from the command line
	std::string Dir;

	DiagnosticEngine& Diags;

public:
	Driver(DiagnosticEngine& diags)
			: Diags(diags) {
	}

	//int ParseArguments();
};

} // namespace arvcc

#endif
