#include <locale>
#include <windows.h>
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
	for (unsigned int i = 0; i < v.size(); i++)
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

	if (asd.matchCouple(2))
	{
		asd.SortCouples();
		asd.PrintCouples();
	}
	else
	{
		cout << "Inga par hittades..\n";
	}
	//PersonList test;
	//test.readFile("boys.txt");
	//test.erasePerson("Bengt");
}
void testSort()
{
	Person p1("AAA");
	Person p2("AAB");
	Person p3("AAC");
	Person p4("ABC");

	if (p1.firstName.compare(p2.firstName) < 0)
		cout << "p1 är störst\n";
	else
		cout << "p2 är störst\n";

	//if (p1 < p2)
	//	cout << "asd\n";
	//else
	//	cout << "hej\n";

	//AAA < AAB
	//AAC > AAB
	//AAB > AAA
}
void mainLoop()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");

	Dating date;
	int input;
	bool done = false;

	cout << "=========DEJT=========\n";
	
	cout << "Läser in personer från databasen";
	for (int i = 0; i < 30; i++)
	{
		cout << ".";
		Sleep(10);
	}
	date.readFile("boys.txt", "girls.txt");

	cout << "\nAnge hur många intressen som ska matchas. Avsluta med -1: ";
	cin >> input;

	if (date.matchCouple(input))
	{
		cout << "\n\n";
		date.SortCouples();
		date.PrintCouples();
	}
	else
		cout << "Inga par hittades..\n\n";

}
int main()
{
	//testPersonInterest();
	//testPersonList();
	//testDating();
	//testSort();
	mainLoop();


	cout<<"\n\n";
	system("pause");
}