//===---------------------------------------------------===//
//
// Abstract Representation for a single form
// of Driver argument.
//
//===---------------------------------------------------===//

#include "Option/Option.h"
#include "Option/Arg.h"

using namespace arvcc::opt;

bool Option::matches(OptSpecifier ID) const { return getID() == ID.getID(); }

Option::Option(const OptTable::Info *info, const OptTable *owner)
    : Info(info), Owner(owner) {}

std::unique_ptr<Arg> Option::accept(const ArgList &Args, std::string CurArg,
                                    unsigned &Index) const {
  // FIXME: consider CroupedShortOption
  auto A(getKind() == FlagClass ? std::make_unique<Arg>(*this, CurArg, Index)
                                : acceptInternal(Args, CurArg, Index));

  if (!A)
    return nullptr;
  return A;
}

std::unique_ptr<Arg> Option::acceptInternal(const ArgList &Args,
                                            std::string CurArg,
                                            unsigned &Index) const {
  return nullptr;
}
