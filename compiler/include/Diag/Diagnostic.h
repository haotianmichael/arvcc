#ifndef ARVCC_DIAGNOSTIC_H
#define ARVCC_DIAGNOSTIC_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace arvcc {
namespace Diag {
class DiagnosticEngine {
public:
  void DiagError(std::string message);
};
} // namespace Diag

} // namespace arvcc
#endif
