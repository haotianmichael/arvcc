#ifndef ARVCC_DIAGNOSTIC_H
#define ARVCC_DIAGNOSTIC_H

#include <iostream>
#include <string>

using namespace std;

namespace arvcc {

class DiagnosticEngine {
private:
	const char** Args;
	int          ArgNumber;

public:
	DiagnosticEngine(const char** argv, int argc)
			: Args(argv), ArgNumber(argc) {
	}

	bool hasArgs();
	void DiagError(std::string message);
};

} // namespace arvcc
#endif
