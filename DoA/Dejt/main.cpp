
#include "Person.h"
#include "Dating.h"
#include "PersonList.h"
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
void testPersonList()
{
	PersonList boys;
	boys.readFile("boys.txt");
	boys.PrintList();

	PersonList girls;
	girls.readFile("girls.txt");
	girls.PrintList();
}
void testDating()
{
	Dating asd;
	asd.readFile("boys.txt", "girls.txt");
	asd.matchCouple(2);

	asd.PrintCouples();

	//PersonList test;
	//test.readFile("boys.txt");
	//test.erasePerson("Bengt");
}
int main()
{
	//testPersonInterest();
	//testPersonList();
	testDating();


	system("pause");
}