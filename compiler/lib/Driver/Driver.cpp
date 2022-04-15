//===---------------------------------===//
//
// This file implements the Driver-related interfaces.
//
//===---------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc;
using namespace arvcc::driver;

Compilation *Driver::BuildCompilation() {

  bool ContainsError;
  CLOptions =
      std::make_unique<opt::InputArgList>(ParseArgStrings(ContainsError));

  opt::DerivedArgList *TranslateArgs = TranslateInputArgs(Args);

  // TODO: Get Tools for different kinds of host machine.

  Compilation *C =
      new Compilation(*this, CLOptions.release(), TranslateArgs, ContainsError);
  if (!HandleImmediateArgs(*C)) {
    return C;
  }

  return C;
}

int Driver::ExecuteCompilation(Compilation &C) { return 0; }

// vector<const char*> ---> vector<Args>
opt::InputArgList Driver::ParseArgStrings(bool ContainsError) {

  unsigned MissingArgIndex;
  unsigned MissingArgCount;
  opt::InputArgList Args =
      getOpts().ParseArgs(this->Args, MissingArgIndex, MissingArgCount);

  return Args;
}

bool Driver::HasCC1Tool() {

  auto FirstArg = std::find_if(Args.begin(), Args.end(),
                               [](const char *A) { return A != nullptr; });
  return (FirstArg != Args.end() && !strcmp(*FirstArg, "-cc1"));
}

opt::DerivedArgList *
Driver::TranslateInputArgs(const opt::InputArgList &Args) const {

  const opt::OptTable &Opts = getOpts();
  opt::DerivedArgList *DAL = new opt::DerivedArgList(Args);

  for (unsigned ii = 0, e = Args.getNumInputArgString(); ii < e; ii++) {
    opt::Arg *A = Args.getInputArg(ii);
    // TODO: Handling options

    DAL->append(A);
  }

  return DAL;
}

bool Driver::HandleImmediateArgs(const Compilation &C) {

  if (C.getArgs().hasArg(_HELP) || C.getArgs().hasArg(__HELP_HIDDEN)) {
    PrintHelp(C.getArgs().hasArg(__HELP_HIDDEN));
    return false;
  }

  if (C.getArgs().hasArg(__VERSION)) {
    PrintVersion(C);
    return false;
  }

  return true;
}

void PrintVersion(Compilation &C) {}

void PrintHelp(bool showHidden) {}
