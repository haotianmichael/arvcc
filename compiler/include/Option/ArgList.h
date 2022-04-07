//===-----------------------------------------===//
//
// Define class of the parsed args.
//
//===-----------------------------------------===//

#ifndef ARVCC_ARGLIST_H
#define ARVCC_ARGLIST_H

#include "Option/Option.h"

namespace arvcc {
namespace opt {

// arg_iterator - Iterates through arguments stored inside an ArgList
template <typename BaseIter, unsigned NumOptSpecifiers = 0> class arg_iterator {
  BaseIter Current, End;

  OptSpecifier Ids[NumOptSpecifiers ? NumOptSpecifiers : 1];

  void SkipToNextArg() {
    for (; Current != End; ++Current) {
      // Skip erased elements
      if (!*Current)
        continue;

      if (!NumOptSpecifiers)
        return;

      const Option &O = (*Current)->getOption();
      for (auto Id : Ids) {
        if (!Id.isValid())
          break;
        if (O.matches(Id))
          return;
      }
    }
  }

  using Traits = std::iterator_traits<BaseIter>;

public:
  using value_type = typename Traits::value_type;
  using reference = typename Traits::reference;
  using pointer = typename Traits::pointer;
  using iterator_category = std::forward_iterator_tag;
  using difference_type = std::ptrdiff_t;

  arg_iterator(
      BaseIter Current, BaseIter End,
      const OptSpecifier (&Ids)[NumOptSpecifiers ? NumOptSpecifiers : 1] = {})
      : Current(Current), End(End) {
    for (unsigned I = 0; I != NumOptSpecifiers; ++I)
      this->Ids[I] = Ids[I];
    SkipToNextArg();
  }

  reference operator*() const { return *Current; }
  pointer operator->() const { return Current; }

  arg_iterator &operator++() {
    ++Current;
    SkipToNextArg();
    return *this;
  }

  arg_iterator &operator++(int) {
    arg_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  friend bool operator==(arg_iterator LHS, arg_iterator RHS) {
    return LHS.Current == RHS.Current;
  }

  friend bool operator!=(arg_iterator LHS, arg_iterator RHS) {
    return !(RHS == LHS);
  }
};

// Ordered collection of driver arguments.
class ArgList {
public:
  using arglist_type = std::vector<Arg *>;
  using iterator = arg_iterator<arglist_type::iterator>;
  using const_iterator = arg_iterator<arglist_type::const_iterator>;
  using reverse_iterator = arg_iterator<arglist_type::reverse_iterator>;
  using const_reverse_iterator =
      arg_iterator<arglist_type::const_reverse_iterator>;

private:
  arglist_type Args;
};

class InputArgList : ArgList {};
} // namespace opt

} // namespace arvcc

#endif
