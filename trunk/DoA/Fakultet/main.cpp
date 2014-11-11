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

	w.restart();
	for (int i = 0; i < nLoop; i++) {
		;
	}
	t0 = w.elapsedUs();

	cout << "Rekursiv:\n";
	w.restart();
	for (int n = 1; n < 10; n++)
	{
		cout << n << "!=" << fakultet_rekursiv(n) << endl;
	}
		t1 = w.elapsedUs();

	w.restart();
	cout << "\nIterativ:\n";
	for (int n = 1; n < 10; n++)
	{
		cout << n << "!=" << fakultet_iterativ(n) << endl;
	}
	t2 = w.elapsedUs();


	cout << 1e3*double(t1.count() - t0.count()) / nLoop;
	cout << 1e3*(t2.count() - t0.count()) / (double)nLoop << endl;

	cout << endl;
	system("pause");
}