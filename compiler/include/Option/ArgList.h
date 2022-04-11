#ifndef ARVCC_ARGLIST_H
#define ARVCC_ARGLIST_H

#include "Option/Option.h"

namespace arvcc {
namespace opt {

// Ordered collection of driver arguments.
class ArgList {
private:
  std::vector<Arg *> Args;

protected:
  ArgList() = default;

  // Explicit move operations to ensure the container is cleared post-move
  // otherwise it could lead to a double-delete in the case of moving of an
  // InputArgList which deletes the contents of the container. If we could fix
  // up the ownership here(delegate storage/ownership to the deriverd class so
  // it can be a container of unique_ptr), this would be simpler.
  ArgList(ArgList &&RHS) : Args(std::move(RHS.Args)) { RHS.Args.clear(); }

  ArgList &operator=(ArgList &&RHS) {
    Args = std::move(RHS.Args);
    RHS.Args.clear();
    return *this;
  }

  ~ArgList() = default;

public:
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
  InputArgList() = default;
  InputArgList(std::vector<const char *>);
  ~InputArgList() { ReleaseMemory(); }

  InputArgList(InputArgList &&RHS)
      : ArgList(std::move(RHS)), ArgStrings(std::move(RHS.ArgStrings)) {}

  InputArgList &operator=(InputArgList &&RHS) {
    ReleaseMemory();
    ArgList::operator=(std::move(RHS));
    ArgStrings = std::move(RHS.ArgStrings);
    return *this;
  }

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
