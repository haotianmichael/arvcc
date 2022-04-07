#include "Option/OptTable.h"
#include "Option/ArgList.h"
#include <iostream>
#include <vector>

using namespace arvcc::opt;

OptTable::OptTable(const std::vector<Info> Infos) : OptionInfos(Infos) {}

std::unique_ptr<Arg> OptTable::ParseOneArg(const ArgList &Args,
                                           unsigned &Index) const {}

InputArgList OptTable::ParseArgs(std::vector<const char *> Args,
                                 unsigned &MissingArgIndex,
                                 unsigned &MissingArgCount) const {

  //InputArgList input(Args.begin(), Args.end());

  //return input;
}
