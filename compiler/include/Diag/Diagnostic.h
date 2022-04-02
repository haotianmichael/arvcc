#ifndef ARVCC_DIAGNOSTIC_H
#define ARVCC_DIAGNOSTIC_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace arvcc {

class DiagnosticEngine {
public:
	void DiagError(std::string message);
};

} // namespace arvcc
#endif
