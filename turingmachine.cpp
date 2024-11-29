#include "turingmachine.h"

std::string TuringMachine::calc (std::string const& init, int maxsteps)
{
	int cur_st = prog_->get_st ();
	tape_.init (init);

	program::iterator pos;
	int steps = 0;
	while ((pos = prog_->find (command (cur_st, *tape_))) != nullptr)
	{
		cur_st = (*pos).get_next_st ();
		*tape_ = (*pos).get_next_sym ();

		unsigned char side = (*pos).get_next_side ();
		if (side == 'L')
		{
			--tape_;
		} else if (side == 'R')
		{
			++tape_;
		}

		if (++steps > maxsteps)
		{
			return "Not applicable";
		}
	}

	std::string result = "";

	int cnt = 0;
	do
	{
		--tape_;
		++cnt;
	} while (*tape_ == '0');

	while (cnt <= tape_.size ())
	{
		result = *tape_ + result;
		--tape_;
		++cnt;
	}

	return result;
}