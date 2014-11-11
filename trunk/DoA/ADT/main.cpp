#include <iostream>
#include <clocale>
#include "interval.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "swedish");
	interval<int> i1;
	interval<double> i2(5.0, 10);
	interval<double> i3(2.5, 10);

	i2.print_relative();
	cout << i2 + i3 << endl;

	interval<double> str�m1((2e-3), 1);
	interval<double> sp�nning1(5.0, 1);


	cout << "Effekten P=U*I f�r m�tdata 1: " << str�m1*sp�nning1 << endl;
	cout << "Resistansen R=U/I f�r m�tdata 1: " << sp�nning1/str�m1  << endl;

	cout << endl;

	interval<double> str�m3((2e-3), 4);
	interval<double> sp�nning3(5.0, 2);

	cout << "Effekten P=U*I f�r m�tdata 3: " << str�m3*sp�nning3 << endl;
	cout << "Resistansen R=U/I f�r m�tdata 3: " << sp�nning3/str�m3 << endl;

	system("pause");
}