#ifndef ARVCC_OPTION_H
#define ARVCC_OPTION_H

#include "Option/OptTable.h"

namespace arvcc {

namespace opt {

class Option {
public:
  // For the goal of parsing different kinds of CL arguments
  enum OptionClass {
    GroupClass = 0,
    InputClass,
    UnknownClass,
    FlagClass,
    JoinedClass,
    ValuesClass,
    SeparateClass,
    RemainingArgClass,
    RemainingArgsJoinedClass,
    CommaJoinedClass,
    MultiArgClass,
    JoinedOrSeparateClass,
    JoinedAndSeparateClass
  };

protected:
  const OptTable::Info *Info;
  const OptTable *Owner;

public:
  Option(const OptTable::Info *Info, const OptTable *Owner);

  bool matches(OptSpecifier ID) const;

  unsigned getID() const { return Info->ID; }
};

} // namespace opt

} // namespace arvcc

#endif
