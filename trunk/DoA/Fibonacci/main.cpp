#include <iostream>
#include <clocale>
#include "Watch.h"

using namespace std;

int fibonacci_rekursiv(int n)
{
	if (n < 2)
		return 1;
	else
	{
		return fibonacci_rekursiv(n - 1) + fibonacci_rekursiv(n - 2);
	}
}
int fibonacci_iterativ(int n)
{
	if (n < 2)
		return 1;
	else
	{
		int a0, a1, a2;
		a0 = a1 = a2 = 1;

		for (int i = 2; i <= n; i++)
		{
			a2 = a1 + a0;
			a0 = a1;
			a1 = a2;
		}
		return a2;
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		cout << fibonacci_rekursiv(i) << " ";
	cout << endl;

	for (int i = 0; i < 6; i++)
		cout << fibonacci_iterativ(i) << " ";

	cout << endl;
	system("pause");
}