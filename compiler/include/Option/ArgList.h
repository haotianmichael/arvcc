#ifndef ARVCC_ARGLIST_H
#define ARVCC_ARGLIST_H

#include "Option/Arg.h"
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
  virtual const char *getArgString(unsigned Index) const = 0;
  virtual unsigned getNumInputArgString() const = 0;

  void ReleaseMem();
  void append(Arg *A);
  unsigned size() { return Args.size(); }
  Arg *getArg(unsigned Index) const { return Args[Index]; }

  // Return the last argument matching Id. or nullptr.
  bool hasArg(OptSpecifier Ids) const {
    Arg *Res = nullptr;
    for (Arg *A : Args) {
      if (A->getOption().matches(Ids)) {
        Res = A;
        Res->claim();
      }
    }
    return Res != nullptr;
  }

  // Return the last argument Id, or null. Do not "claim" the
  // option (don't mark it as having been used).
  bool hasArgNoClaim(OptSpecifier Ids) const {
    Arg *Res = nullptr;
    for (Arg *A : Args) {
      if (A->getOption().matches(Ids)) {
        Res = A;
      }
    }
    return Res != nullptr;
  }
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

  unsigned getNumInputArgString() const override { return ArgStrings.size(); }

  void replaceArgStrings(unsigned Index, const char *S) {
    ArgStrings[Index] = std::move(S);
  }
};

// DerivedArgList
class DerivedArgList final : public ArgList {
  const InputArgList &BaseArgs;

public:
  DerivedArgList(const InputArgList &BaseArgs);

  const char *getArgString(unsigned Index) const override {
    return BaseArgs.getArgString(Index);
  }

  unsigned getNumInputArgString() const override {
    return BaseArgs.getNumInputArgString();
  }

  const InputArgList &getBaseArgs() const { return BaseArgs; }
};
} // namespace opt

} // namespace arvcc

#endif
