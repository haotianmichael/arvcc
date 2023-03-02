#ifndef ARVCC_DRIVER_UTIL_H
#define ARVCC_DRIVER_UTIL_H

#include <vector>

namespace arvcc {

namespace driver {
class Action;

// ActionList - Type used for lists of actions.
typedef std::vector<Action *> ActionList;
} // namespace driver

} // namespace arvcc

#endif
