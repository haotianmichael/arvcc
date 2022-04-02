#ifndef ARVCC_DRIVER_H
#define ARVCC_DRIVER_H

#include <iostream>
#include <string>

namespace arvcc {

class Driver {

public:
	/// The name of driver
     std::string Name;

	/// The path the driver executable was invoked
	/// from the command line
     std::string Dir;
};

} // namespace arvcc

#endif
