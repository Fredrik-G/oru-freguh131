#include <iostream>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

double sum(int limit)
{
	int i = 1;
	double temp = 0.0;
	while(i<=limit)
		temp += 1/sqrt(i++);

	return temp;
}
double sumRecursive(int limit, int i)
{
	if(i==limit)
		return 1/sqrt(i);
	else
		return 1/sqrt(i) + sumRecursive(limit, i+1);
}


void main3_1()
{
	cout<<sum(5)<<endl;
	cout<<sumRecursive(5,1)<<endl;
}
void main3_2()
{

}



int main()
{
	main3_1();
	//main3_2();


	system("pause");
}
