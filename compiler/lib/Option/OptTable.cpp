//===---------------------------------------------------===//
//
// Provide access to the Option info Table.
//
//===---------------------------------------------------===//

#include "Option/OptTable.h"
#include "Option/Arg.h"
#include "Option/ArgList.h"
#include <algorithm>

using namespace arvcc::opt;

OptTable::OptTable(const std::vector<Info> Infos) : OptionInfos(Infos) {
  for (unsigned i = 1; i < OptionInfos.size(); i++) {
    if (const char *const *P = getInfo(i).Prefix) {
      for (; *P != nullptr; ++P) {
        PrefixesUnion.insert(*P);
      }
    }
  }

  for (auto prefix : PrefixesUnion) {
    std::string Str(prefix);
    for (unsigned i = 0; i < Str.size(); ++i) {
      char C = Str[i];
      if (std::string::size_type position =
              PrefixChars.find(C) == std::string::npos)
        PrefixChars.push_back(C);
    }
  }
}

static bool isInput(std::set<const char *> PrefixesUnion, const char *str) {
  // FIXME: should we deal with --version/---version
  for (auto prefix : PrefixesUnion) {
    if (!std::string(str).find(prefix))
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
    return std::make_unique<Arg>(getOption(InputOptionID), std::string(Str),
                                 Index++, Str);

  auto getName = [this](const char *Ctr) -> std::string {
    std::string Str(Ctr);
    std::string::size_type pos = Str.find_first_not_of(PrefixChars);
    return Str.substr(pos);
  };

  std::string target = getName(Str);
  auto Start = std::find_if(
      OptionInfos.begin(), OptionInfos.end(),
      [&target](Info A) -> bool { return !strcmp(A.Name, target.c_str()); });

  Option Opt(&*Start, this);
  if (std::unique_ptr<Arg> A = Opt.accept(Args, Str, Index))
    return A;

  if (Prev != Index)
    return nullptr;

  return std::make_unique<Arg>(getOption(UnknownOptionID), std::string(Str),
                               Index++, Str);
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
