//===-----------------------------------------===//
//
// Define class of the parsed args.
//
//===-----------------------------------------===//

#ifndef ARVCC_ARG_H
#define ARVCC_ARG_H

#include "Option/Option.h"
#include <iostream>
#include <string>

namespace arvcc {
namespace opt {

class Arg {
private:
	const Option opt;

	unsigned index;

	std::string value;

public:
	const Option& getOption() {
		return opt;
	}

	unsigned getIndex() {
		return index;
	}

	std::string& getValue() {
		return value;
	}
};

} // namespace opt

} // namespace arvcc
#endif

