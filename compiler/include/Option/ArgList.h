//===-----------------------------------------===//
//
// Define class of the parsed args.
//
//===-----------------------------------------===//

#ifndef ARVCC_ARGLIST_H
#define ARVCC_ARGLIST_H

#include "Option/OptSpecifier.h"
#include "Option/Option.h"

namespace arvcc {
namespace opt {

// arg_iterator - Iterates through arguments stored inside an ArgList
template <typename BaseIter, unsigned NumOptSpecifiers = 0>
class arg_iterator {
	BaseIter Current, End;

	OptSpecifier Ids[NumOptSpecifiers ? NumOptSpecifiers : 1];

	void SkipToNextArg() {
		for (; Current != End; ++Current) {
			// Skip erased elements
			if (!*Current)
				continue;

			if (!NumOptSpecifiers)
				return;

			const Option& O = (*Current)->getOption();
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
    
};

// Ordered collection of driver arguments.
class ArgList {
};

class InputArgList : ArgList {
};
} // namespace opt

} // namespace arvcc

#endif
