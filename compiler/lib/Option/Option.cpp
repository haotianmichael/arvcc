#include "Option/Option.h"
#include "Option/OptSpecifier.h"

using namespace arvcc::opt;

bool Option::matches(OptSpecifier ID) const { return getID() == ID.getID(); }

Option::Option(const OptTable::Info *info, const OptTable *owner)
    : Info(info), Owner(owner) {}
