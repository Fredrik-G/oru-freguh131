#include <iostream>
#include <clocale>

#include "circular_list.h"
#include "Josephus.h"
using namespace std;


void main4_1()
{
	circular_list cl1;
	cl1.add("kalle");
	cl1.add("asd");
	cl1.add("dfhgk");
	cl1.print();

	cl1.remove();
	cl1.print();

	circular_list cl2;
	for (int i = 1; i < 5; i++)
	{
		string asd = static_cast<ostringstream*>(&(ostringstream() << i))->str();
		cl2.add(asd);
	}
	int n = 4;
	for (auto it = cl2.begin(); it != cl2.end(); it++)
	{
		string asd = static_cast<ostringstream*>(&(ostringstream() << n--))->str();
		if (it->value == asd)
			cout << "lika";
		//cout << it->value << " ";
	}

	/*circular_list cl2;
	cl2 = cl1;
	cout << endl;
	cl2.print();*/

}
void main4_copy()
{
	circular_list cl1;
	cl1.add("kalle");
	cl1.add("asd");

	cout << "list1: "; cl1.print();
	circular_list cl2(cl1);
	cout << "list2: "; cl2.print();


	//cout << endl;

	//circular_list cl3;

	//cl3 = cl1;

	////cout << "list3: "; cl3.print();

}
void main4_2()
{
	Josephus asd;
	asd.add("Person6");
	asd.add("Person5");
	asd.add("Person4");
	asd.add("Person3");
	asd.add("Person2");
	asd.add("Person1");

	asd.eliminate();

	//asd.print();
}
int main()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");
	//main4_1();
	//main4_copy();
	main4_2();

	cout << endl;
	system("pause");
}