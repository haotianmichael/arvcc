#ifndef ARVCC_COMPILATION_H
#define ARVCC_COMPILATION_H

#include "Driver/Driver.h"

namespace arvcc {

class Compilation {
	const Driver& Dir;

	// Whether an error during parsing the input args
	bool ContainsError;

public:
	Compilation(const Driver& dir)
			: Dir(dir) {
	}

	bool containsError() const {
		return ContainsError;
	}
};

} // namespace arvcc
#endif
