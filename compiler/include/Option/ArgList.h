//===-----------------------------------------===//
//
// Define class of the parsed args.
//
//===-----------------------------------------===//

#ifndef ARVCC_ARGLIST_H
#define ARVCC_ARGLIST_H

#include "Option/Option.h"

namespace arvcc {
namespace opt {

// Ordered collection of driver arguments.
class ArgList {
private:
  std::vector<Arg *> Args;

public:
  ~ArgList() { ReleaseMem(); }

  void ReleaseMem();
  void append(Arg *A);
  virtual const char *getArgString(unsigned Index) const = 0;
};

// InputArgList
class InputArgList final : public ArgList {
private:
  mutable std::vector<const char *> ArgStrings;

  void ReleaseMemory();

public:
  InputArgList(std::vector<const char *>);
  ~InputArgList() { ReleaseMemory(); }

  const char *getArgString(unsigned Index) const override {
    return ArgStrings[Index];
  }

  void replaceArgStrings(unsigned Index, const char *S) {
    ArgStrings[Index] = std::move(S);
  }
};
} // namespace opt

} // namespace arvcc

#endif
