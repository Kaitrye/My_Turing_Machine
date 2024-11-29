#include "command.h"

int command::get_status () const
{
	return q_i;
}

int command::get_symbol () const
{
	return a_j;
}

int command::get_next_st () const
{
	return q_k;
}

int command::get_next_sym () const
{
	return a_m;
}

int command::get_next_side () const
{
	return d_n;
}

bool command::is_equal (const command& other) const
{
	return (q_i == other.q_i) && (a_j == other.a_j);
}

bool command::is_less (const command& other) const
{
	return (q_i < other.q_i) || ((q_i == other.q_i) && (a_j < other.a_j));
}

bool operator<(const command& left, const command& right)
{
	return left.is_less (right);
}

bool operator==(const command& left, const command& right)
{
	return left.is_equal (right);
}

bool operator!=(const command& left, const command& right)
{
	return !(left == right);
}

bool operator<=(const command& left, const command& right)
{
	return (left < right) || (left == right);
}

bool operator>(const command& left, const command& right)
{
	return right < left;
}

bool operator>=(const command& left, const command& right)
{
	return !(left < right);
}

std::istream& operator>> (std::istream& in, command& X)
{
	int cur_st;
	unsigned char cur_sym;

	int next_st;
	unsigned char next_sym;
	unsigned char side;

	in.ignore ();
	in >> cur_st;
	in >> cur_sym;

	in.ignore ();
	in.ignore ();
	in.ignore ();
	in.ignore ();
	in.ignore ();

	in >> next_st;
	in >> next_sym;
	in >> side;

	in.ignore ();

	X = command (cur_st, cur_sym, next_st, next_sym, side);

	return in;
}