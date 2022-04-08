#include "Option/OptTable.h"
#include "Option/Arg.h"
#include "Option/ArgList.h"
#include <iostream>
#include <vector>

using namespace arvcc::opt;

OptTable::OptTable(const std::vector<Info> Infos) : OptionInfos(Infos) {}

static bool isInput(const char *str) { return true; }

const Option OptTable::getOption(OptSpecifier Opt) const {
  unsigned id = Opt.getID();
  if (id == 0)
    return Option(nullptr, nullptr);

  return Option(&getInfo(id), this);
}

std::unique_ptr<Arg> OptTable::ParseOneArg(const ArgList &Args,
                                           unsigned &Index) const {

  unsigned Prev = Index;
  const char *Str = Args.getArgString(Index);
  if (isInput(Str))
    return std::make_unique<Arg>(getOption(InputOptionID), Index, Str);

  return std::make_unique<Arg>(getOption(UnknownOptionID), Index, Str);
}

InputArgList OptTable::ParseArgs(std::vector<const char *> Args,
                                 unsigned &MissingArgIndex,
                                 unsigned &MissingArgCount) const {

  MissingArgCount = MissingArgIndex = 0;
  InputArgList input(Args);
  unsigned Index = 0, End = Args.size();
  while (Index < End) {
    if (input.getArgString(Index) == nullptr) {
      ++Index;
      continue;
    }

    const char *Str = input.getArgString(Index);
    if (!strcmp(Str, "")) {
      ++Index;
      continue;
    }

    unsigned Prev = Index;
    std::unique_ptr<Arg> A = ParseOneArg(input, Index);
    if (!A) {
      MissingArgIndex = Prev;
      MissingArgCount = Index - Prev - 1;
    }

    input.append(A.release());
  }
  return input;
}
