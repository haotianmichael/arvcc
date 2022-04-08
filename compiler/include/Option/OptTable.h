//===-------------------------------------------------===//
//
// Provide access to the Option info table.
// ===-------------------------------------------------===//

#ifndef ARVCC_OPTION_TABLE_H
#define ARVCC_OPTION_TABLE_H
#include "Option/OptSpecifier.h"
#include <iostream>
#include <vector>

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
    const char *Name;
    unsigned ID;
    unsigned char Kind;
    unsigned char Param;
    const char *Values;
  };

private:
  // The option information table.
  std::vector<Info> OptionInfos;
  unsigned InputOptionID = 0;
  unsigned UnknownOptionID = 0;

public:
  const Info &getInfo(OptSpecifier Opt) const {
    unsigned id = Opt.getID();
    return OptionInfos[0];
  }

  OptTable(const std::vector<Info> OptionInfos);
  ~OptTable() = default;

public:
  // Return the corresponding option
  const Option getOption(OptSpecifier Opt) const;

  const char *getOptionName(OptSpecifier id) const { return getInfo(id).Name; }

  const char *getOptionValues(OptSpecifier id) const {
    return getInfo(id).Values;
  }

  unsigned getOptionID(OptSpecifier id) const { return getInfo(id).ID; }

  unsigned char getOptionKind(OptSpecifier id) const {
    return getInfo(id).Kind;
  }

  unsigned char getOptionParam(OptSpecifier id) const {
    return getInfo(id).Param;
  }

  // Parse a single argument.
  std::unique_ptr<Arg> ParseOneArg(const ArgList  &Args, unsigned &Index) const;

  // Parse a list of arguments into an InputArgList.
  InputArgList ParseArgs(std::vector<const char *> Args,
                         unsigned &MissingArgIndex,
                         unsigned &MissingArgCount) const;
};

} // namespace opt

} // namespace arvcc

#endif
