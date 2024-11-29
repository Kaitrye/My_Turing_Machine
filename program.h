#ifndef program_
#define program_

#include "command.h"

class program
{
	struct Node
	{
		Node* left_;
		Node* right_;
		Node* parent_;
		command data_;
		signed char balance_;

		Node (const command& X) : left_ (nullptr), right_ (nullptr), parent_ (nullptr), data_ (X), balance_ (0) {}

		size_t height () const
		{
			size_t L = (left_ == nullptr) ? 0 : left_->height ();
			size_t R = (right_ == nullptr) ? 0 : right_->height ();

			return (L < R) ? R + 1 : L + 1;
		}

		Node* minimum ()
		{
			Node* now = this;
			while (now->left_ != nullptr)
			{
				now = now->left_;
			}

			return now;
		}

		Node* maximum ()
		{
			Node* now = this;
			while (now->right_ != nullptr)
			{
				now = now->right_;
			}

			return now;
		}

		Node* next ()
		{
			if (right_ != nullptr)
			{
				return right_->minimum ();
			}

			Node* now = this;
			Node* parent = now->parent_;

			while (parent != nullptr && now == parent->right_)
			{
				now = parent;
				parent = now->parent_;
			}

			return parent;
		}

		Node* prev ()
		{
			if (left_ != nullptr)
			{
				return left_->maximum ();
			}

			Node* now = this;
			Node* parent = now->parent_;

			while (parent != nullptr && now == parent->left_)
			{
				now = parent;
				parent = now->parent_;
			}

			return parent;
		}

		~Node ()
		{
			delete left_;
			delete right_;
		}
	};

	Node* root_; // корень дерева.
	size_t count_; // количество элементов в дереве.
	int start_; // начальное состояние для МТ.

	// функции поворотов для балансировки.
	Node* rightRotate (Node*);
	Node* leftRotate (Node*);
	Node* bigRightRotate (Node*);
	Node* bigLeftRotate (Node*);

public:
	program () : root_ (nullptr), count_ (0), start_(0) {}

	int get_st () const;
	void set_st (int st);

	size_t size () const;
	size_t height () const;

	class iterator
	{
		Node* current_;

	public:
		iterator (Node* x = nullptr) : current_ (x) {}

		command& operator*()
		{
			return current_->data_;
		}

		bool operator==(const iterator& other)
		{
			return (current_ == other.current_);
		}
		bool operator!=(const iterator& other)
		{
			return (current_ != other.current_);
		}

		iterator& operator++()
		{
			if (current_ != nullptr)
			{
				current_ = current_->next ();
			} else
			{
				throw "Iterator: out of the bounds";
			}

			return *this;
		}
		iterator operator++(int)
		{
			iterator tmp (current_);

			if (current_ != nullptr)
			{
				current_ = current_->next ();
			} else
			{
				throw "Iterator: out of the bounds";
			}

			return tmp;
		}

		friend class program;
	};

	iterator begin () const;
	iterator end () const;

	class reverse_iterator
	{
		Node* current_;

	public:
		reverse_iterator (Node* x = nullptr) : current_ (x)
		{}

		command& operator*()
		{
			return current_->data_;
		}

		bool operator==(const reverse_iterator& other)
		{
			return (current_ == other.current_);
		}
		bool operator!=(const reverse_iterator& other)
		{
			return (current_ != other.current_);
		}

		reverse_iterator& operator++()
		{
			if (current_ != nullptr)
			{
				current_ = current_->prev ();
			} else
			{
				throw "Iterator: out of the bounds";
			}

			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp (current_);

			if (current_ != nullptr)
			{
				current_ = current_->prev ();
			} else
			{
				throw "Iterator: out of the bounds";
			}

			return tmp;
		}

		friend class program;
	};

	reverse_iterator rbegin () const;
	reverse_iterator rend () const;

	void insert (const command&);
	iterator find (const command&) const;
	void erase (const iterator&);

	void clear ();
	~program ();
};

#endif // program_