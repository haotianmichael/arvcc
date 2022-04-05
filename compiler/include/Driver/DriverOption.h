#ifndef ARVCC_DRIVEROPTION_H
#define ARVCC_DRIVEROPTION_H
#include "Option/OptTable.h"

namespace arvcc {
namespace opt {

static const std::vector<OptTable::Info> InfoTable = {
	OptTable::Info{ "-cc1", 0, '0', ' ', "compiler frontend" }
};

class DriverOptTable : public OptTable {
public:
	DriverOptTable()
			: OptTable(InfoTable) {
	}
};

const opt::OptTable& getDriverOptionTable() {

	static const DriverOptTable* Table = []() {
		auto Result = std::unique_ptr<DriverOptTable>();
		return Result.release();
	}();
	return *Table;
}

} // namespace opt
} // namespace arvcc

#endif
