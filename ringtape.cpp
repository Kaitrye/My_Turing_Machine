#include "ringtape.h"

int ringTape::size () const
{
	return count_;
}

void ringTape::init (const std::string& str)
{
	int i = 0;
	for (; i < str.size (); ++i)
	{
		buf_[i] = str[i];
	}

	for (; i < count_; ++i)
	{
		buf_[i] = '0';
	}
}

char& ringTape::operator*()
{
	return buf_[current_ % count_];
}

ringTape& ringTape::operator++()
{
	++current_;
	if (current_ == count_)
	{
		current_ = 0;
	}

	return *this;
}

ringTape ringTape::operator++(int)
{
	ringTape tmp (*this);
	++(*this);

	return tmp;
}

ringTape& ringTape::operator--()
{
	if (current_ == 0)
	{
		current_ = count_;
	}
	--current_;

	return *this;
}

ringTape ringTape::operator--(int)
{
	ringTape tmp (*this);
	--(*this);

	return tmp;
}

ringTape::~ringTape ()
{
	delete[] buf_;
}
