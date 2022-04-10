#ifndef ARVCC_DRIVEROPTION_H
#define ARVCC_DRIVEROPTION_H
#include "Option/OptTable.h"

namespace arvcc {
namespace driver {

// Driver Option's Prefixes
#define PREFIX(NAME, VALUE) static const char *const NAME[] = VALUE;
#define COMMA ,
PREFIX(prefix_0, {nullptr})
PREFIX(prefix_1, {"-" COMMA nullptr})
PREFIX(prefix_2, {"/" COMMA "-" COMMA nullptr})
PREFIX(prefix_3, {"--" COMMA nullptr})
PREFIX(prefix_4, {"-" COMMA "--" COMMA nullptr})
#undef COMMA

enum ClangFlags {
  NoXarchOption = (1 << 4),
  Unsupported = (1 << 7),
  CoreOption = (1 << 8),
  CLOption = (1 << 9),
  CC1Option = (1 << 10),
  NoDriverOption = (1 << 12),
  Ignored = (1 << 17),
};

// Driver Option Table
// {Prefix Name ID Kind Flags HelpText}
using INFO = opt::OptTable::Info;
static const std::vector<opt::OptTable::Info> InfoTable = {
    INFO{prefix_0, &"<input>"[0], 0, '0', 0, nullptr},
    INFO{prefix_0, &"<unknown>"[0], 0, '0', 0, nullptr},
    INFO{prefix_1, &"-###"[1], 0, '0', CoreOption,
         "Print (but do not run) the commands to run for this compilation"},
    INFO{prefix_1, &"cc1"[1], 0, '0', CC1Option | NoDriverOption, nullptr},
    INFO{prefix_1, &"-E"[1], 0, '0', CC1Option, "Only run the preproccessor"},
    INFO{prefix_1, &"-S"[1], 0, '0', CC1Option,
         "Only run preprocess and compilation steps"},
    INFO{prefix_1, &"-c"[1], 0, '0', NoXarchOption,
         "Only run preprocess, compile, and assemble steps"},
    INFO{prefix_1, &"-o"[1], 0, '0', NoXarchOption | CC1Option,
         "Write output to <file>", "<file>"},
    INFO{prefix_1, &"-I"[1], 0, '0', CC1Option,
         "Add directory to the end of the list of include search paths",
         "<dir>"}};

class DriverOptTable : public opt::OptTable {
public:
  DriverOptTable() : OptTable(InfoTable) {}
};

static const opt::OptTable &getDriverOptionTable() {

  static const DriverOptTable Tab = DriverOptTable();
  return Tab;
}

#undef PREFIX

} // namespace driver
} // namespace arvcc

#endif
