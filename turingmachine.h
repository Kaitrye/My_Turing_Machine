#ifndef turingmachine_
#define turingmachine_

#include "ringtape.h"
#include "program.h"

class TuringMachine
{
	ringTape tape_; // рабочая лента машины Тьюринга.
	const program* prog_; // программа машины Тьюринга.

public:
	TuringMachine(const program& p, int len) : prog_(&p), tape_(len) {};

	std::string calc (std::string const&, int);
};

#endif // turingmachine_
