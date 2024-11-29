#ifndef ringtape_
#define ringtape_

#include <string>

class ringTape
{
	char* buf_; // кольцевая лента.
	int current_; // текущий символ, на который указывает головка.
	int count_; // длина ленты.

public:
	ringTape (int len = 10) : current_(0), buf_(new char[len]), count_(len) {}

	int size () const;
	void init(const std::string& str = "");
	char& operator*();

	ringTape& operator++();
	ringTape operator++(int);
	ringTape& operator--();
	ringTape operator--(int);

	~ringTape ();
};

#endif // ringtape_
