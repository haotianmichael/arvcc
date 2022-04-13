//===-------------------------------------===//
//
// Define class of the parsed args.
//
//===-------------------------------------===//

#include "Option/Arg.h"
#include "Option/Option.h"

using namespace arvcc::opt;

Arg::Arg(const Option Opt, std::string S, unsigned Index)
    : opt(Opt), Spelling(S), index(Index), OwnsValues(false) {}

Arg::Arg(const Option Opt, std::string S, unsigned Index, const char *Value)
    : opt(Opt), Spelling(S), index(Index), OwnsValues(false) {
  value.push_back(Value);
}

Arg::~Arg() {
  if (OwnsValues) {
    for (unsigned i = 0, e = value.size(); i != e; i++) {
      delete[] value[i];
    }
  }
}
