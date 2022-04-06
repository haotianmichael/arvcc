#ifndef ARVCC_DRIVEROPTION_H
#define ARVCC_DRIVEROPTION_H
#include "Option/OptTable.h"

namespace arvcc {
namespace driver {

static const std::vector<opt::OptTable::Info> InfoTable = {
    opt::OptTable::Info{"-cc1", 0, '0', ' ', "compiler frontend"}};

class DriverOptTable : public opt::OptTable {
public:
  DriverOptTable() : OptTable(InfoTable) {}
};

static const opt::OptTable &getDriverOptionTable() {

  static const DriverOptTable Tab = DriverOptTable();
  return Tab;
}

} // namespace driver
} // namespace arvcc

#endif
