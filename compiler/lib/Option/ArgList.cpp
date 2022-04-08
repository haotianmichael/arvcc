#include "Option/ArgList.h"
#include "Option/Arg.h"

using namespace arvcc::opt;

InputArgList::InputArgList(std::vector<const char *> ArgArr)
    : ArgStrings(ArgArr) {}

void ArgList::append(Arg *A) { this->Args.push_back(A); }

void ArgList::ReleaseMem() {
  for (auto Arg : this->Args) {
    delete Arg;
  }
}

void InputArgList::ReleaseMemory() {
  ReleaseMem();
  for (auto Arg : this->ArgStrings) {
    delete Arg;
  }
}
