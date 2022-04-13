#ifndef ARVCC_OPTION_H
#define ARVCC_OPTION_H

#include "Option/OptTable.h"

namespace arvcc {

namespace opt {

class Option {
public:
  // For the goal of parsing different kinds of CL arguments
  enum OptionClass {
    GroupClass = 0,
    InputClass,
    UnknownClass,
    FlagClass,
    JoinedClass,
    ValuesClass,
    SeparateClass,
    RemainingArgClass,
    RemainingArgsJoinedClass,
    CommaJoinedClass,
    MultiArgClass,
    JoinedOrSeparateClass,
    JoinedAndSeparateClass
  };

protected:
  const OptTable::Info *Info;
  const OptTable *Owner;

public:
  Option(const OptTable::Info *Info, const OptTable *Owner);

  bool isValid() const { return Info != nullptr; }

  unsigned getID() const { return Info->ID; }

  OptionClass getKind() const { return OptionClass(Info->Kind); }

  std::string getName() const { return Info->Name; }

  std::string getMetaVar() const { return Info->MetaVar; }

  std::string getHelpText() const { return Info->HelpText; }

  bool matches(OptSpecifier ID) const;

  // Potentially accept the current argument, returning a
  // new Arg instance, or 0 of the option does not accept
  // this argument (or the argument is missing values).
  std::unique_ptr<Arg> accept(const ArgList &Args, std::string CurArg,
                              unsigned &Index) const;

private:
  std::unique_ptr<Arg> acceptInternal(const ArgList &Args, std::string CurArg,
                                      unsigned &Index) const;
};

} // namespace opt

} // namespace arvcc

#endif
