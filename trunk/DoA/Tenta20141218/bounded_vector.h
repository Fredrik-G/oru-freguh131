#pragma once
#include <string>
#include <iostream>
using namespace std;
class bounded_vector
{
private:
	int lowIndex, highIndex, *vptr, size;
public:

	bounded_vector()
	{
		lowIndex=highIndex=size=0;
		vptr=nullptr;
	}

	bounded_vector(int lowIndex, int highIndex)
	{
		this->lowIndex=lowIndex;
		this->highIndex=highIndex;

		size=highIndex-lowIndex+1;
		vptr=new int[size];
		for(int i=0;i<size;i++)
			vptr[i]=0;
	}
	bounded_vector(const bounded_vector &obj)
	{//copy constructor
		lowIndex = obj.lowIndex;
		highIndex = obj.highIndex;
		size = obj.size;
		vptr = new int[size];

		for(int i=0;i<size;i++)
			vptr[i]=obj.vptr[i];      
	}
	bounded_vector &operator=(const bounded_vector &obj)
	{//copy assignment operator

		this->clear();

		lowIndex = obj.lowIndex;
		highIndex = obj.highIndex;
		size = obj.size;
		vptr = new int[size];

		for (int i=0;i<size;i++)
			vptr[i] = obj.vptr[i];

		return *this;
	}
	friend bounded_vector &operator+(const bounded_vector &lop, const bounded_vector &rop)
	{
		if(lop.size>rop.size)
		{
			bounded_vector temp(lop.lowIndex, lop.highIndex);

			for(int i=0;i<rop.size;i++)
				temp.vptr[i] = lop.vptr[i] + rop.vptr[i];

			return temp;
		}
		else
		{
			bounded_vector temp(lop.lowIndex, lop.highIndex);
			return temp;
		}

	}

	void clear()
	{
		if(vptr!=nullptr)
			delete vptr;
		else
			return;
	}

	void print()
	{
		cout<<endl;
		for(int i=0;i<size;i++)
			cout << vptr[i]<<" ";
	}

	int &operator[](int pos)
	{
		if (pos>=lowIndex && pos<=highIndex)
			return vptr[pos-lowIndex];
		else
			throw exception("bounded_vector::operator[], out of bounds");
	}




	~bounded_vector()
	{
		this->clear();
	}
};

