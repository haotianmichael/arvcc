//===-------------------------------------------===//
//
// Input & Temporary Driver Types
//
//===-------------------------------------------===//

#ifndef ARVCC_DRIVER_TYPES_H
#define ARVCC_DRIVER_TYPES_H
#include "Option/ArgList.h"
#include <vector>

namespace arvcc {
namespace driver {
class Driver;

namespace types {
enum ID {
  TY_INVALID,
#define TYPE(NAME, ID, PP_TYPE, TEMP_SUFFIX, ...) TY_##ID,
#include "Driver/DriverTypes.h"
#undef TYPE
  TY_LAST
};

} // namespace types
} // namespace driver

} // namespace arvcc

#endif
