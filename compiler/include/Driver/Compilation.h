#ifndef ARVCC_COMPILATION_H
#define ARVCC_COMPILATION_H

namespace arvcc {
namespace opt {
class DerivedArgList;
class InputArgList;

} // namespace opt
} // namespace arvcc

namespace arvcc {
namespace driver {

class Driver;

// Compilation - A set of tasks to perform for a single driver
// invocation.
class Compilation {
  // The driver we were created by.
  const Driver &Dir;

  // The original (untranslated) input argument list.
  opt::InputArgList *Args;

  // The driver translated arguments.
  opt::DerivedArgList *TranslateArgs;

  // Whether an error during parsing the input args
  bool ContainsError;

public:
  Compilation(const Driver &dir, opt::InputArgList *args,
              opt::DerivedArgList *translateArgs, bool containsError)
      : Dir(dir), Args(args), TranslateArgs(translateArgs),
        ContainsError(containsError) {}

  ~Compilation();

  const Driver &getDriver() const { return Dir; }

  const opt::InputArgList &getInputArgs() const { return *Args; }

  const opt::DerivedArgList &getArgs() const { return *TranslateArgs; }

  bool containsError() const { return ContainsError; }
};

} // namespace driver
} // namespace arvcc
#endif
