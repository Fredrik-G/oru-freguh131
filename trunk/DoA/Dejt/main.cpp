
#include "Person.h"
#include "Dating.h"

using namespace std;
void testPersonInterest()
{
	Person kalle("kalle");
	kalle.AddInterest("bio");
	kalle.AddInterest("dans");

	vector<string> v = kalle.GetInterest();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << kalle;
}
int main()
{
	//testPersonInterest();

	Dating asd;
	asd.readFile("boys.txt");


	system("pause");
}