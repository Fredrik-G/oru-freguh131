#include <array>
#include <exception>
using namespace std;
template <class T>
class forward_list {
private:
	T *front;
	int count;
	array<T, 100> items;
public:
	forward_list()
	{
		front = nullptr;
		count = 0;
	}
	~forward_list()
	{
	}

	void push_front(const T &n)
	{
		items[++count] = n;
	}
	T pop_front()
	{
		if (!empty())
			return items[count--];
	}
	void clear()
	{
		fill(items.begin(), items.end(), 0);
	}
	bool empty() { return count == 0; }

	class iterator
	{
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(int junk) { ptr_++; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	iterator begin()
	{
		return iterator(&items[0]);
	}
	iterator end()
	{
		return iterator(&items[count + 1]);
	}
};