#include <iostream>
#include <clocale>
#include <array>
using namespace std;

int array_sum(array<int, 5> v)
{
	int sum = 0, index = 5;

	if (index <= v.size() && index > 0)
	{
		index--;
		sum += array_sum(v);
	}

	return sum;
}
int array_produkt(array<int, 5> v)
{
	return 1;
}

int main()
{
	array<int, 5> myints = { 1, 2, 3, 4, 5 };

	cout << "Sum: " << array_sum(myints);

	cout << endl;
	system("pause");
}