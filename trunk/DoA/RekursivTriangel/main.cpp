#include <iostream>
using namespace std;

void triangle(ostream& outs, unsigned int m, unsigned int n)
{
	if (m > n)
		return;
	else if (m <= n)
	{
		for (int i = 0; i < m; i++)
			outs << "*";

		outs << endl;
		triangle(cout, m+1, n);

		for (int k = 0; k < m; k++)
			outs << "*";

		outs << endl;
	}
}
int main()
{
	triangle(cout, 1, 5);

	system("pause");
	return 1;
}