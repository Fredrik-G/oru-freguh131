#include <iostream>
#include <clocale>
#include <string>
#include "forward_list.h"
using namespace std;

int main()
{
	//COPY CONSTRUCTOR
	forward_list<int> fl1,fl2,fl3;

	for (int i = 1; i < 15; i++)
		fl1.push_front(i);
	forward_list<int> fl4(fl1);
	cout << "List1\tList4\n";
	for (int i = 14; i > 0; i--)
	{
		cout << fl1.front() << "\t" << fl4.front() << endl;
		fl1.pop_front();
		fl4.pop_front();
	}
	//COPY ASSIGNMENT
	fl2.push_front(1);
	fl2.push_front(2);
	fl3.push_front(3);
	fl3.push_front(4);
	fl3 = fl2;
	cout << "\n\n";
	for (int i = 2; i > 0; i--)
	{
		cout << fl2.front() << "\t" << fl3.front() << endl;
		fl2.pop_front();
		fl3.pop_front();
	}
	system("pause");
	system("cls");
//***********************************************
		fl1.push_front(10);
		fl1.push_front(20);
		fl1.push_front(30);
		cout << "Tom? " << fl1.empty() << endl;

		cout << fl1.ListAll();
		
		fl1.pop_front();
		cout << "\n\n" << fl1.ListAll();

		fl1.clear();
		cout << "\nTom nu?\n" << fl1.ListAll();

		fl1.push_front(10);
		fl1.push_front(20);
		fl1.push_front(30);
		cout << "\n\n\n";
		for (auto it = fl1.begin(); it != fl1.end(); it++)
		{
			cout << it->value << endl;
		}

		for (auto &n : fl1)
		{
			cout << n.value << endl;
		}
		fl2.push_front(30);
		fl2.push_front(40);
		string asd = fl2.ListAll();
		cout << "\nlängd: " << asd.length() << "\nsize: " << asd.size();
		cout << "Sista elementet: ";
		
	system("pause");
}