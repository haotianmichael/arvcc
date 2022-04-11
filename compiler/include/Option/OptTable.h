#ifndef ARVCC_OPTION_TABLE_H
#define ARVCC_OPTION_TABLE_H
#include "Option/OptSpecifier.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <set>

namespace arvcc {

namespace opt {

class Arg;
class ArgList;
class InputArgList;
class Option;

class OptTable {
public:
  // Entry for a single option instance in the option data table.
  struct Info {
    const char *const *Prefix;
    const char *Name;
    unsigned ID = 0;
    unsigned char Kind = '0';
    unsigned int Flags;
    const char *HelpText;
    const char *MetaVar = nullptr;
  };

private:
  // The option information table.
  std::vector<Info> OptionInfos;
  unsigned InputOptionID = 0;
  unsigned UnknownOptionID = 0;

  // The union of all option prefixes, If an argument does not begin with
  // one of these, it is an input.
  std::set<const char*> PrefixesUnion;

public:
  const Info &getInfo(OptSpecifier Opt) const {
    unsigned id = Opt.getID();
    assert(id > 0 && id - 1 < OptionInfos.size() && "Invalid Option ID.");
    return OptionInfos[id - 1];
  }

  OptTable(const std::vector<Info> OptionInfos);
  ~OptTable() = default;

public:
  // Return the corresponding option
  const Option getOption(OptSpecifier Opt) const;

  // get elements
  const char *getOptionName(OptSpecifier id) const { return getInfo(id).Name; }

  const char *getOptionHelp(OptSpecifier id) const {
    return getInfo(id).HelpText;
  }

  unsigned getOptionID(OptSpecifier id) const { return getInfo(id).ID; }

  unsigned char getOptionKind(OptSpecifier id) const {
    return getInfo(id).Kind;
  }

  // Parse a single argument.
  std::unique_ptr<Arg> ParseOneArg(const ArgList &Args, unsigned &Index) const;

  // Parse a list of arguments into an InputArgList.
  InputArgList ParseArgs(std::vector<const char *> Args,
                         unsigned &MissingArgIndex,
                         unsigned &MissingArgCount) const;
};

} // namespace opt

} // namespace arvcc

#endif
