//===-----------------------------------===//
//
// This file implements the Diagnostic-related interfaces
//
//===-----------------------------------===//
#include "Diag/Diagnostic.h"

using namespace arvcc::Diag;

void DiagnosticEngine::DiagError(std::string message) {
  fprintf(stderr, "arvcc-1.0: \033[;31merror:\033[0m \e[1m%s\n",
          message.c_str());
  exit(1);
}
