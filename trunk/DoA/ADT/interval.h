#include <iostream>
#pragma once
using namespace std;
template<class T>
class interval
{
private:
	T lower, upper;
public:

	interval()
	{
		lower = upper = 0;
	}
	interval(T mean, double procent)
	{
		lower = (T)(mean - mean*procent / 100);
		upper = (T)(mean + mean*procent / 100);
	}
	T mean()
	{
		return (lower + upper) / 2;
	}
	double relative_error()
	{
		return (upper - lower) / mean();
	}
	void print_relative()
	{
		cout << "Medel=" << mean() << ", relative error = " << relative_error() << endl;
	}
	friend interval<T> operator+(const interval<T> &lop, const interval<T> &rop)
	{
		interval<T> m;

		m.upper = lop.upper + rop.upper;
		m.lower = lop.lower + rop.lower;
		return m;
	}
	friend interval<T> operator*(const interval<T> &lop, const interval<T> &rop)
	{
		interval<T> m;

		m.upper = lop.upper * rop.upper;
		m.lower = lop.lower * rop.lower;
		return m;
	}
	friend interval<T> operator/(const interval<T> &lop, const interval<T> &rop)
	{
		interval<T> m;

		m.upper = lop.upper / rop.upper;
		m.lower = lop.lower / rop.lower;
		return m;
	}
	friend ostream& operator<<(ostream &out, const interval<T> &rop)
	{
		out << "(" << rop.lower << "," << rop.upper << ")";
		return out;
	}



	~interval()
	{
	}
};

