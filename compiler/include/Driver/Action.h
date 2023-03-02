#ifndef ARVCC_DRIVER_ACTION_H
#define ARVCC_DRIVER_ACTION_H

#include "Driver/Driver.h"
#include "Driver/Util.h"

namespace arvcc {
namespace opt {
class Arg;
}
} // namespace arvcc

namespace arvcc {
namespace driver {

// Action - Represent an abstract compilation step to perform.
class Action {
public:
  using size_type = ActionList::size_type;

  enum ActionClass {
    InputClass = 0,
    PreprocessJobClass,
    PreCompileJobClass,
    CompileJobClass,
    BackendJobClass,
    LinkJobClass,
  };

private:
  ActionClass Kind;

  // The output type of the action.
  types::ID Type;

  ActionList Inputs;
};

} // namespace driver

} // namespace arvcc
#endif

