#include <iostream>
#include <clocale>
#include "Watch.h"
using namespace std;

int fakultet_rekursiv(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fakultet_rekursiv(n - 1);
}
int fakultet_iterativ(int n)
{
	int tal = 1;
	for (int i = 1; i <= n; i++)
		tal = i*tal;
	return tal;
}
int main()
{
	Course::Watch w;
	Course::microseconds t0, t1, t2;
	long nLoop = 1000000L;
	int x, y, n_max = 0;

	cout.precision(1);
	cout.setf(ios::fixed);
	system("color 1f");
	while (n_max != -1)
	{
		cout << "Ange n. Avsluta med -1: ";
		cin >> n_max;

		if (n_max != -1)
			cout << "\n\tRekursiv \tIterativ\n";

		for (int n = 1; n <= n_max; n++)
		{
			w.restart();
			for (int i = 0; i < nLoop; i++)
				;
			t0 = w.elapsedUs();

			w.restart();

			for (int i = 0; i < nLoop; i++)
				x = fakultet_rekursiv(n);
			t1 = w.elapsedUs();

			w.restart();
			for (int i = 0; i < nLoop; i++)
				y = fakultet_iterativ(n);
			t2 = w.elapsedUs();

			cout << n << "!: " << 1e3*double(t1.count() - t0.count()) / nLoop << "\t" << x;
			cout << "\t" << 1e3*(t2.count() - t0.count()) / (double)nLoop << "\t" << y << endl;
		}
		cout << "\n\n";
	}

	cout << endl;
	system("pause");
}