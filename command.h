#ifndef command_
#define command_

#include <iostream>

class command
{
	int q_i; // текущее состояние.
	unsigned char a_j; // текущий символ.

	int q_k; // следующее состояние.
	unsigned char a_m; // следующий символ.
	unsigned char d_n; // символ перехода головки.

public:
	command (int cur_st = 0, unsigned char cur_sym = 0, int next_st = 0, unsigned char next_sym = 0, unsigned char side = 0) : 
		q_i(cur_st), a_j(cur_sym), q_k(next_st), a_m(next_sym), d_n(side) {}

	int get_status () const;
	int get_symbol () const;
	int get_next_st () const;
	int get_next_sym () const;
	int get_next_side () const;

	bool is_equal (const command&) const;
	bool is_less (const command&) const;
};

bool operator<(const command&, const command&);
bool operator==(const command&, const command&);
bool operator!=(const command&, const command&);
bool operator<=(const command&, const command&);
bool operator>(const command&, const command&);
bool operator>=(const command&, const command&);

std::istream& operator>> (std::istream&, command&);

#endif // command_