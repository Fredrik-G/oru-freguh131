#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

template<class T>
struct Node
{
	T value;
	Node<T> *next;

	Node(){ next = nullptr; }
	Node(T t)
	{
		value = t;
		next = nullptr;
	}
};

template <class T>
class forward_list
{
private:
	Node<T> *head;
public:
	class iterator
	{
	public:
		typedef iterator self_type;
		typedef Node<T>  value_type;
		typedef Node<T>& reference;
		typedef Node<T>* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;

		iterator(pointer ptr) : ptr_(ptr) { } //Constructor
		self_type operator++()
		{
			self_type i = *this;
			ptr_ = ptr_->next;
			return i;
		}
		self_type operator++(int junk) { ptr_ = ptr_->next; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }

	private:
		pointer ptr_;
	};

	forward_list()
	{
		head = nullptr;
	}
	forward_list(const forward_list<T> &old)
	{//Copy constructor
		Node<T> *tail = nullptr;
		Node<T> *v = old.head;
		while (v != nullptr)
		{
			Node<T> *n = new Node<T>(v->value);
			if (this->head == nullptr)
				this->head = tail = n;
			else
				tail = tail->next = n;

			v = v->next;
		}
	}
	forward_list<T>& operator=(const forward_list<T> &rop)
	{//Copy Assignment Operator
	 //Som copy constructor fast t�mmer listan f�rst.
		if (!empty())
			clear();

		Node<T> *tail = nullptr;
		Node<T> *v = rop.head;
		while (v != nullptr)
		{
			Node<T> *n = new Node<T>(v->value);
			if (this->head == nullptr)
				this->head = tail = n;
			else
				tail = tail->next = n;

			v = v->next;
		}
		return *this;
	}
	~forward_list()
	{
	}
//	virtual ~forward_list();
	void push_front(const T &value)
	{
		Node<T> *n = new Node<T>(value);
		n->next = head;
		head = n;
	}
	void pop_front()
	{
		Node<T> *n = head;
		if (!empty())
		{
			head = head->next;
			delete n;
		}
	}
	void clear()
	{
		while (!empty())
			pop_front();
	}
	bool empty() { return head == nullptr; }

	T& front()
	{//front - Access av f�rsta elementet i listan.		
		if (!empty())
			return head->value;
	}
	string ListAll()
	{
		ostringstream oss;
		Node<T> *n = head;
		if (n == nullptr)
			return "";
		do
		{
			oss << n->value << endl;
			n = n->next;
		} while (n != nullptr);

		return oss.str();
	}
	void insert_after(iterator &it, T value)
	{
		Node<T> *n = new Node<T>(value);
		n->next = it->next;
		it->next = n;
	}
	void erase_after(iterator &it)
	{//erase_after - Tag bort ett element efter.
		Node<T> *d = it->next;
		it->next = d->next;
		delete d;
	}
	void swap(forward_list<T> &fl)
	{//swap - Byt plats p� inneh�llet.
		forward_list<T> temp;
		temp = fl;
		fl = *this;
		*this = temp;
	}
	
	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
};