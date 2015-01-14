#include <iostream>
#include <string>
#include <deque>
#include <locale>
#include <cmath>

#include "../hr_time.h"
#include "../Watch.h"

#include "map_ip.h"
#include "bounded_vector.h"
using namespace std;

int fakultet_rekursiv(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fakultet_rekursiv(n - 1);
}
double sumRecursive(double x, int i, int limit)
{
	if (i == limit)
		return pow(x, i) / fakultet_rekursiv(i);
	else
	{
		return (pow(x, i) / fakultet_rekursiv(i)) + sumRecursive(x,i+1,limit);
	}
}

double sum(double x, int i, int limit)
{
	double sum = 0;
	while (i <= limit)
	{
		sum += pow(x, i) / fakultet_rekursiv(i);
		i++;
	}
	return sum;
}

void main3_1ab()
{
	cout << sum(2, 0, 10) << endl;
	cout << sumRecursive(2, 0, 10) << endl;
}
void main3_1c()
{
#define ANTAL_GGR 1.3e7
	CStopWatch csw;
	double totTime = 0.0;

	for (unsigned int i = 0; i < ANTAL_GGR; i++)
	{
		csw.startTimer();
		sum(2, 0, 10);
		csw.stopTimer();
		totTime += csw.getElapsedTime();
	}
	cout << "Total tid för iterativa funktionen: " << totTime << "s och dess medeltid: " << totTime / ANTAL_GGR<<"s\n";

	totTime = 0.0;
	for (unsigned int i = 0; i < ANTAL_GGR; i++)
	{
		csw.startTimer();
		sumRecursive(2, 0, 10);
		csw.stopTimer();
		totTime += csw.getElapsedTime();
	}

	cout << "Total tid för rekursiva funktionen: " << totTime << "s och dess medeltid: " << totTime / ANTAL_GGR << "s\n";
}

void main3_2()
{
	map_ip ip;
	ip.readFile("ip_one.txt");
	//ip.test();
	//ip.search("117.154.115.1");
	ip.PrintMostFrequent(5);
}

void main_4()
{
	//bounded_vector bv(0,3);
	//bv[2]++;
	//bounded_vector bv2(bv);
	//bv.print();
	//bv2.print();


	//bounded_vector bv3(0,2),bv4(0,3);
	//cout<<endl;
	//bv3[0]++;
	//bv4[2]++;
	//bv3.print();
	//bv4.print();


	//bounded_vector bv5 = (bv3 + bv4);

	//bv5.print();

	bounded_vector bv1(0, 10);
	bounded_vector bv2(0, 5);
	bv1[0] = 1;
	bv1[1] = 2;
	bv1[2] = 3;
	bv1[3] = 4;

	bounded_vector bv3 = (bv1 + bv2);
	bv1.print();
	bv2.print();
	bv3.print();

}


int main()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");

	//main3_1ab();
	//main3_1c();

	//main3_2();

	//main3_3a
	//main3_3b1();
	//main3_3b2();

	main_4();

	cout<<"\n\n";
	system("pause");
}
