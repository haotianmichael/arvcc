#ifndef ARVCC_COMPILATION_H
#define ARVCC_COMPILATION_H

#include "Driver/Driver.h"

namespace arvcc {

class Compilation {
	const Driver& Dir;

public:
	Compilation(const Driver& dir)
			: Dir(dir) {
	}
};

} // namespace arvcc
#endif
