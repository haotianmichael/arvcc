//===--------------------------------------===//
//
//
// Abstract Representation for a single form
// of Driver argument
//
//===--------------------------------------===//

#ifndef ARVCC_OPTION_H
#define ARVCC_OPTION_H

#include "Option/OptTable.h"

namespace arvcc {

namespace opt {

class Option {
protected:
  const OptTable::Info *Info;
  const OptTable *Owner;

public:
  Option(const OptTable::Info *Info, const OptTable *Owner);

  bool matches(OptSpecifier ID) const;
};

} // namespace opt

} // namespace arvcc

#endif
