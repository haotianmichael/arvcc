#ifndef ARVCC_DRIVER_H
#define ARVCC_DRIVER_H

#include "Diag/Diagnostic.h"
#include "Driver/DriverOption.h"
#include "Driver/DriverTypes.h"
#include "Option/ArgList.h"
#include "Option/OptTable.h"

using namespace arvcc::Diag;

namespace arvcc {
namespace driver {

class Compilation;
class Driver {

private:
  // The path the driver executable was invoked
  // from the command line
  std::string Dir;

  DiagnosticEngine &Diags;

  // command line arguments
  std::vector<const char *> PreArgs;

  // parsed arguments
  std::unique_ptr<opt::InputArgList> CLOptions;

  // An input type and its arguments
  using InputTy = std::pair<types::ID, const opt::Arg *>;

  // A list of inputs and their types for the given arguments
  using InputList = std::vector<InputTy>;

public:
  Driver(DiagnosticEngine &diags, const char **args, int argc)
      : Diags(diags), Dir(args[0]) {
    if (1 == argc)
      Diags.DiagError("no Input files");
    for (int i = 1; i < argc; i++)
      PreArgs.push_back(args[i]);
  }

private:
  // Create a new derived argument list from the input argument,
  // after applying the standard argument translations.
  opt::DerivedArgList *TranslateInputArgs(const opt::InputArgList &Args) const;

public:
  /*
   * @name Accessors
   * */

  // Arguments Parsing Tools
  const opt::OptTable &getOpts() const { return getDriverOptionTable(); }

  /*
   * @
   * @name Primary Functionality
   * @
   * */

  // Construct a Compilation object for a
  // command line arguments vector
  Compilation *BuildCompilation();

  // Parse the given list of strings into an
  // ArgList
  opt::InputArgList ParseArgStrings(bool ContainsError);

  // Construct the list of inputs and their types from
  // the given arguments
  void BuildInpts(opt::DerivedArgList &Args, InputList &Inputs) const;

  // Execute a compilation according to
  // command line arguments
  int ExecuteCompilation(Compilation &C);

  // Compiler Frontend
  bool HasCC1Tool();

  int ExecuteCC1Tool();

  /*
   * @
   * @name Helper Methods
   * @
   * */

  // Handle any arguments which should be
  // treated before building actions or building tools.
  bool HandleImmediateArgs(const Compilation &C);

  // Print the help text.
  void PrintHelp(bool ShowHidden) const;

  // Print the driver version
  void PrintVersion(const Compilation &C) const;
};

} // namespace driver
} // namespace arvcc

#endif
