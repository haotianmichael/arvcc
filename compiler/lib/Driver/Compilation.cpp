//===-------------------------------------------------===//
//
// Compilation Task Implementation
//
//===-------------------------------------------------===//

#include "Driver/Compilation.h"
#include "Driver/Driver.h"

using namespace arvcc::driver;

Compilation::~Compilation() {

  delete TranslateArgs;
  delete Args;
}
