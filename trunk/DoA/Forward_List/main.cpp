#include <iostream>
#include <clocale>
#include "forward_list.h"
using namespace std;

int main()
{
	forward_list<int> fl1,fl2,fl3;

		fl1.push_front(10);
		fl1.push_front(20);
		fl1.push_front(30);
		cout << "Tom? " << fl1.empty() << endl;

		fl1.pop_front();
		fl1.pop_front();
		fl1.pop_front();
		cout << "Tom? " << fl1.empty() << endl;

	system("pause");
}