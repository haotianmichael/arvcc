//===-----------------------------------------===//
//
// Define class of the parsed args.
//
//===-----------------------------------------===//

#ifndef ARVCC_ARG_H
#define ARVCC_ARG_H

#include "Option/Option.h"
#include <iostream>

namespace arvcc {
namespace opt {

// A concrets instance of a particular driver option
class Arg {
private:
  // The option this argument is an instance of.
  const Option opt;

  // The index at which this argument appears in the
  // ArgList
  unsigned index;

  // The argument values
  std::vector<const char *> value;

public:
  Arg(const Option Opt, unsigned Index);
  Arg(const Option Opt, unsigned Index, const char *Value);
  Arg(const Arg &) = delete;
  Arg &operator=(const Arg &) = delete;
  ~Arg();

  const Option &getOption() { return opt; }

  unsigned getIndex() { return index; }

  std::vector<const char *> &getValue() { return value; }
};

} // namespace opt

} // namespace arvcc
#endif

