#include "Option/OptTable.h"
#include <vector>

using namespace arvcc::opt;

OptTable::OptTable(const std::vector<Info> Infos)
		: OptionInfos(Infos) {
}

std::unique_ptr<Arg> OptTable::ParseOneArg(const ArgList& Args, unsigned& Index) const {
}

