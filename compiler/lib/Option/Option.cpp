//===---------------------------------------------------===//
//
// Abstract Representation for a single form
// of Driver argument.
//
//===---------------------------------------------------===//

#include "Option/Option.h"
#include "Option/Arg.h"
#include "Option/ArgList.h"

using namespace arvcc::opt;

bool Option::matches(OptSpecifier ID) const { return getID() == ID.getID(); }

Option::Option(const OptTable::Info *info, const OptTable *owner)
    : Info(info), Owner(owner) {}

std::unique_ptr<Arg> Option::accept(const ArgList &Args, std::string CurArg,
                                    unsigned &Index) const {

  size_t ArgSize = CurArg.size();
  switch (getKind()) {
  case FlagClass: {
    if (ArgSize != strlen(Args.getArgString(Index)))
      return nullptr;
    return std::make_unique<Arg>(*this, CurArg, Index++);
  }
  case JoinedOrSeparateClass: {
    if (ArgSize != strlen(Args.getArgString(Index))) {
      const char *Value = Args.getArgString(Index) + ArgSize;
      return std::make_unique<Arg>(*this, CurArg, Index++, Value);
    }
    Index += 2;
    if (Index > Args.getNumInputArgString() ||
        Args.getArgString(Index - 1) == nullptr)
      return nullptr;

    return std::make_unique<Arg>(*this, CurArg, Index - 2,
                                 Args.getArgString(Index - 1));
  }
  case SeparateClass: {
    if (ArgSize != strlen(Args.getArgString(Index)))
      return nullptr;

    Index += 2;
    if (Index > Args.getNumInputArgString() ||
        Args.getArgString(Index - 1) == nullptr)
      return nullptr;
    return std::make_unique<Arg>(*this, CurArg, Index - 2,
                                 Args.getArgString(Index - 1));
  }
  default: {
    return nullptr;
  }
  }
}

