#include <iostream>
#include <string>
#include <deque>

#include "Observatory.h"

#include "../hr_time.h"
#include "../Watch.h"
using namespace std;

double powerOf(double x, int n)
{
	if(n==0)
		return 1;
	double temp = x;
	while(n>1)
	{
		temp = temp*x;
		n--;
	}
	return temp;
}
double powerOfRecursive(double x, int n)
{
	if(n<0)
		return -1;
	else if(n==0)
		return 1;
	else if(n==1)
		return x*n;
	else
		return x*powerOfRecursive(x,n-1);
}

void main3_1ab()
{
	cout<<powerOf(2,10)<<endl;
	cout<<powerOfRecursive(2,10)<<endl;
}
void main3_1c()
{
	#define ANTAL_GGR 1.3e7
	CStopWatch csw;
	double totalTime=0.0;

	for(unsigned int i=0;i<ANTAL_GGR;i++)
	{
		csw.startTimer();
		powerOfRecursive(2,10);
		csw.stopTimer();
		totalTime += csw.getElapsedTime();
	}
	double meanTime = totalTime/ANTAL_GGR;
	cout<<"Rekursiva:\nTotal tid: "<<totalTime<<"\nMedeltid: "<<meanTime<<endl;

	totalTime=0.0;
	for(unsigned int i=0;i<ANTAL_GGR;i++)
	{
		csw.startTimer();
		powerOf(2,10);
		csw.stopTimer();
		totalTime += csw.getElapsedTime();
	}
	meanTime = totalTime/ANTAL_GGR;
	cout<<"\n\nIterativa:\nTotal tid: "<<totalTime<<"\nMedeltid: "<<meanTime<<endl;

}
void main3_2()
{
	Observatory asd;
	//asd.readFile("testfil-3.txt");
	asd.readFile("testfil-2000.txt");
	asd.print();
}

void main3_3a()
{


}

int main()
{
	//main3_1ab();
	//main3_1c();

	main3_2();

	system("pause");
}
