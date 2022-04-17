#include "Driver/DriverTypes.h"

using namespace arvcc::driver;
using namespace arvcc::driver::types;

types::ID types::lookupTypeForExtension(std::string Ext) {
  types::ID ResIs = TY_INVALID;
  if (Ext == "c") {
    ResIs = TY_C;
  } else if (Ext == "C" || Ext == "cc" || Ext == "CC" || Ext == "cpp" ||
             Ext == "c++") {
    ResIs = TY_CXX;
  } else if (Ext == "h") {
    ResIs = TY_CHeader;
  } else if (Ext == "H") {
    ResIs = TY_CXXHeader;
  } else if (Ext == "i") {
    ResIs = TY_PP_C;
  } else if (Ext == "o") {
    ResIs = TY_Object;
  } else if (Ext == "s" || Ext == "asm") {
    ResIs = TY_PP_Asm;
  } else if (Ext == "ast") {
    ResIs = TY_AST;
  }
  return ResIs;
}
