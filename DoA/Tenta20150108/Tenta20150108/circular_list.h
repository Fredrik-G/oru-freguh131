#pragma once
#include <array>
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

struct Node
{
	Node *next;
	string value;

	Node(){ next = nullptr; value = "Sentinel"; }
	Node(string value)
	{
		this->value = value;
		next = nullptr;
	}
};
class circular_list
{
private:
	Node *sentinel;
public:
	class iterator
	{
	public:
		typedef iterator self_type;
		typedef Node  value_type;
		typedef Node& reference;
		typedef Node* pointer;
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
	iterator begin() { return iterator(sentinel->next); }
	iterator end()
	{
		Node *temp = sentinel;

		while (temp != sentinel)
			temp = temp->next;

		return iterator(temp);
	}


	circular_list()
	{
		sentinel = new Node();
		sentinel->next = sentinel;
	}
	circular_list(const circular_list &obj)
	{//copy constructor
		//funkar inte 
		this->sentinel = nullptr;
		Node *tail = nullptr;
		Node *v = obj.sentinel;
		do
		{
			Node *ny = new Node(v->value);
			if (this->sentinel == nullptr)
				this->sentinel = tail = ny;
			else
				tail = tail->next = ny;

			v = v->next;
		} while (v->value != "Sentinel");
		
	}
	circular_list& operator=(const circular_list &obj)
	{
	}
	void add(string value)
	{
		Node *n = new Node(value);
		//Node *head = sentinel;
		if (empty())
		{
			sentinel->next = n;
			n->next = sentinel;
		}
		else
		{
			n->next = sentinel->next;
			sentinel->next = n;
		}
	}
	void remove()
	{//Tar bort första noden i listan.
		Node *temp = sentinel->next;
		sentinel->next = sentinel->next->next;
		delete temp;
	}
	void erase_after(iterator &it)
	{//erase_after - Tag bort ett element efter.

		Node *n = it->next;
		it->next = n->next;
		delete n;
	}
	void print()
	{
		Node *n = sentinel->next;
		do
		{
			cout << n->value << " ";
			n = n->next;
		} while (n != sentinel);
		cout << endl;
	}
	string front()
	{
		return sentinel->next->value;
	}
	bool empty()
	{
		if (sentinel->next == sentinel)
			return true;
		else
			return false;
	}
	int count()
	{
		int count = 0;
		Node *n = sentinel->next;
		do
		{	
			count++;
			n = n->next;
		} while (n != sentinel);
		return count;
	}
	void clear()
	{
		delete sentinel;
	}
	~circular_list()
	{
		clear();
	}
};

