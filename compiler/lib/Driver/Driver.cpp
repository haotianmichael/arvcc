//===---------------------------------===//
//
// This file implements the Driver-related interfaces.
//
//===---------------------------------===//

#include "Driver/Driver.h"
#include "Driver/Compilation.h"

using namespace arvcc;
using namespace arvcc::driver;

void Driver::BuildInpts(opt::DerivedArgList &Args, InputList &Inputs) const {

  types::ID InputType = types::TY_Nothing;
  opt::Arg *InputTypeArg = nullptr;

  for (unsigned ii = 0, e = Args.size(); ii < e; ++ii) {
    opt::Arg *A = Args.getArg(ii);
    if (A->getOption().getKind() == opt::Option::InputClass) {
      const char *Value = A->getValue();
      types::ID Ty = types::TY_INVALID;

      // Infer the input type if necessary.
      if (InputType == types::TY_Nothing) {

        // stdin must be handled specially.
        if (memcmp(Value, "-", 2) == 0) {
          if (!Args.hasArgNoClaim(_E)) {
            Diags.DiagError("unknown stdin type.");
          }
          Ty = types::TY_C;
        } else {
          // Otherwise lookup by extension
          if (const char *Ext = strrchr(Value, '.'))
            Ty = types::lookupTypeForExtension(Ext);
        }
      } else {
        if (!InputTypeArg->getOption().matches(_x)) {
          const char *Ext = strrchr(Value, '.');
          if (Ext && types::lookupTypeForExtension(Ext + 1) == types::TY_Object)
            Ty = types::TY_Object;
        }

        if (Ty == types::TY_INVALID) {
          Ty = InputType;
          // InputTypeArg->claim();
        }
      }
      Inputs.push_back(std::make_pair(Ty, A));
    } else if (A->getOption().hasFlag(LinkerInput)) {
      Inputs.push_back(std::make_pair(types::TY_Object, A));
    }
  }
}

Compilation *Driver::BuildCompilation() {

  bool ContainsError;
  CLOptions =
      std::make_unique<opt::InputArgList>(ParseArgStrings(ContainsError));

  opt::DerivedArgList *TranslateArgs = TranslateInputArgs(*CLOptions);

  // TODO: Get Tools for different kinds of host machine.

  Compilation *C =
      new Compilation(*this, CLOptions.release(), TranslateArgs, ContainsError);
  if (!HandleImmediateArgs(*C)) {
    return C;
  }

  // Construct the list of inputs.
  InputList Inputs;
  BuildInpts(*TranslateArgs, Inputs);

  return C;
}

int Driver::ExecuteCompilation(Compilation &C) { return 0; }

// vector<const char*> ---> vector<Args>
opt::InputArgList Driver::ParseArgStrings(bool ContainsError) {

  unsigned MissingArgIndex;
  unsigned MissingArgCount;
  opt::InputArgList Args =
      getOpts().ParseArgs(this->PreArgs, MissingArgIndex, MissingArgCount);

  return Args;
}

bool Driver::HasCC1Tool() {

  auto FirstArg = std::find_if(PreArgs.begin(), PreArgs.end(),
                               [](const char *A) { return A != nullptr; });
  return (FirstArg != PreArgs.end() && !strcmp(*FirstArg, "-cc1"));
}

opt::DerivedArgList *
Driver::TranslateInputArgs(const opt::InputArgList &Args) const {

  const opt::OptTable &Opts = getOpts();
  opt::DerivedArgList *DAL = new opt::DerivedArgList(Args);

  for (unsigned ii = 0, e = Args.getNumInputArgString(); ii < e; ii++) {
    opt::Arg *A = Args.getArg(ii);
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

void Driver::PrintVersion(const Compilation &C) const {}

void Driver::PrintHelp(bool showHidden) const {}
