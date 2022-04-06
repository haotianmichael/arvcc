//===-- driver.cpp- arvcc Driver------------------------===//
//
//
// This is the entry point to arvcc driver; it provides interfaces
// for functionality of arvcc driver library.
//
//===----------------------------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc::driver;
using namespace arvcc;

int main(int Argc, const char **Argv) {

  DiagnosticEngine Diags;
  Driver TheDriver(Diags, Argv, Argc);

  // Handle -cc1 integrated tool
  if (TheDriver.HasCC1Tool()) {
    return TheDriver.ExecuteCC1Tool();
  }

  // Real command line parsing
  std::unique_ptr<Compilation> C(TheDriver.BuildCompilation());
  int Res = 1;
  if (C && !C->containsError()) {
    Res = TheDriver.ExecuteCompilation(*C);
  }

  std::cout << "hello, my name is arvcc." << std::endl;
  return Res;
}
