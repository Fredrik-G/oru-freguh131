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

	interval<double> ström1((2e-3), 1);
	interval<double> spänning1(5.0, 1);


	cout << "Effekten P=U*I för mätdata 1: " << ström1*spänning1 << endl;
	cout << "Resistansen R=U/I för mätdata 1: " << spänning1/ström1  << endl;

	cout << endl;

	interval<double> ström3((2e-3), 4);
	interval<double> spänning3(5.0, 2);

	cout << "Effekten P=U*I för mätdata 3: " << ström3*spänning3 << endl;
	cout << "Resistansen R=U/I för mätdata 3: " << spänning3/ström3 << endl;

	system("pause");
}