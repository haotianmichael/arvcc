#ifndef ARVCC_ARG_H
#define ARVCC_ARG_H

#include "Option/Option.h"

namespace arvcc {
namespace opt {

// A concrets instance of a particular driver option
class Arg {
private:
  // The option this argument is an instance of.
  const Option opt;

  // How this instance of the option was spelled
  std::string Spelling;

  // The index at which this argument appears in the
  // ArgList
  unsigned index;

  // This is used for generating "argument unused" flag
  mutable unsigned Claimed : 1;

  // Does this argument own its value?
  mutable unsigned OwnsValues : 1;

  // The argument values
  std::vector<const char *> value;

public:
  Arg(const Option Opt, std::string Spelling, unsigned Index);
  Arg(const Option Opt, std::string Spelling, unsigned Index,
      const char *Value);
  ~Arg();

  const Option &getOption() { return opt; }

  unsigned getIndex() { return index; }

  std::vector<const char *> &getValues() { return value; }

  const char *getValue(unsigned Index = 0) { return value[Index]; }

  void claim() const { Claimed = true; }
};

} // namespace opt

} // namespace arvcc
#endif

