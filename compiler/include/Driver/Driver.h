#ifndef ARVCC_DRIVER_H
#define ARVCC_DRIVER_H

#include "Diag/Diagnostic.h"

namespace arvcc {

class Compilation;
class Driver {

private:
	// The path the driver executable was invoked
	// from the command line
	std::string Dir;

	DiagnosticEngine& Diags;

	// command line arguments
	std::vector<const char*> Args;

public:
	Driver(DiagnosticEngine& diags, const char** args, int argc)
			: Diags(diags) {
		if (1 == argc)
			Diags.DiagError("no Input files");
		for (int i = 0; i < argc; i++)
			Args.push_back(args[i]);
	}

public:
	// Construct a Compilation object for a
	// command line arguments vector
	Compilation* BuildCompilation();

	// Execute a compilation according to
	// command line arguments
	int ExecuteCompilation(Compilation& C);

	// Compiler Frontend
	int ExecuteCC1Tool();

	void ParseArgStrings();

	bool HasCC1Tool();
};

} // namespace arvcc

#endif
