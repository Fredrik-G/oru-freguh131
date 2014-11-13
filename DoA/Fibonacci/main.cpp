#include <iostream>
#include <chrono>
#include <clocale>
#include "Watch.h"

using namespace std;
bool verbose;
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
	Course::Watch w;
	Course::microseconds t0, t1, t2, t3;
	long nLoop = 1000000L;
	int x, y, n_max, nivå = 0;
	char c;

	setlocale(LC_ALL, "swedish");
	system("color 1f");

	cout << "Ange n: ";
	cin >> n_max;
	cout << "Vill du se utskrift om exekveringsordningen? y/n: ";
	cin >> c;
	if (c == 'y' || c == 'Y')
		verbose = true;
	else if (c == 'n' || c == 'N')
		verbose = false;

	cout << "\n\tRekursiv \tIterativ\n";

	for (int n = 1; n <= n_max; n++)
	{
		w.restart();
		for (int i = 0; i < nLoop; i++)
			;
		t0 = w.elapsedUs();

		w.restart();

		if (verbose)
			cout << "Nivå(" << nivå << "): Beräknar fib(" << n << ")\n";
		nivå++;
		for (int i = 0; i < nLoop; i++)
			x = fibonacci_rekursiv(n);
		t1 = w.elapsedUs();

		w.restart();
		for (int i = 0; i < nLoop; i++)
			y = fibonacci_iterativ(n);
		t2 = w.elapsedUs();

		cout << n << ": " << 1e3*double(t1.count() - t0.count()) / nLoop  << "\t" << x;
		cout << "\t" << 1e3*(t2.count() - t0.count()) / (double)nLoop << "\t" << y << endl;

	}






	//*****************************************
	/*
	for (int i = 0; i < 5; i++)
		cout << fibonacci_rekursiv(i) << " ";
	cout << endl;

	for (int i = 0; i < 6; i++)
		cout << fibonacci_iterativ(i) << " ";

	*/
	cout << endl;
	system("pause");
}