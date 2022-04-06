//===--------------------------------------===//
//
//
//  Wrapper class for abstarcting references to option IDs.
//
//===--------------------------------------===//

#ifndef ARVCC_OPTION_SPECIFIER_H
#define ARVCC_OPTION_SPECIFIER_H

namespace arvcc {
namespace opt {

class Option;

class OptSpecifier {
  unsigned ID = 0;

public:
  // OptSpecifier() = default;
  // explicit OptSpecifier(bool) = delete;
  OptSpecifier(unsigned ID) : ID(ID) {}
  // OptSpecifier(const Option *opt);

  bool isValid() const { return ID != 0; }
  unsigned getID() const { return ID; }

  bool operator==(OptSpecifier Opt) const { return ID == Opt.getID(); }
  bool operator!=(OptSpecifier Opt) const { return !(*this == Opt); }
};

} // namespace opt

} // namespace arvcc

#endif
