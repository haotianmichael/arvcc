//===---------------------------------------------------===//
//
// Provide access to the Option info Table.
//
//===---------------------------------------------------===//

#include "Option/OptTable.h"
#include "Option/Arg.h"
#include "Option/ArgList.h"

using namespace arvcc::opt;

OptTable::OptTable(const std::vector<Info> Infos) : OptionInfos(Infos) {
    for(unsigned i = 0; i < OptionInfos.size(); i ++) {
        if(const char *const *P = getInfo(i).Prefix) {
            PrefixesUnion.push_back(*P);
        } 
    }
}

static bool isInput(std::vector<std::string> PrefixesUnion, const char *str) {

  if (!strcmp(str, "-"))
    return true;
  for (auto prefix : PrefixesUnion) {
    if(strcmp(prefix.c_str(), str))
        return false;
  }
  return true;
}

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
  if (isInput(PrefixesUnion, Str))
    return std::make_unique<Arg>(getOption(InputOptionID), Index++, Str);

  return std::make_unique<Arg>(getOption(UnknownOptionID), Index++, Str);
}

InputArgList OptTable::ParseArgs(std::vector<const char *> Args,
                                 unsigned &MissingArgIndex,
                                 unsigned &MissingArgCount) const {

  MissingArgCount = MissingArgIndex = 0;
  InputArgList Input(Args);
  unsigned Index = 0, End = Args.size();
  while (Index < End) {
    if (Input.getArgString(Index) == nullptr) {
      ++Index;
      continue;
    }

    const char *Str = Input.getArgString(Index);
    if (!strcmp(Str, "")) {
      ++Index;
      continue;
    }

    unsigned Prev = Index;
    std::unique_ptr<Arg> A = ParseOneArg(Input, Index);
    assert(Index > Prev && "Parser failed to consume arguments.");

    if (!A) {
      assert(Index >= End && "Unexpected parser error.");
      assert(Index - Prev - 1 && "No Missing arguments");
      MissingArgIndex = Prev;
      MissingArgCount = Index - Prev - 1;
    }

    Input.append(A.release());
  }
  return Input;
}
