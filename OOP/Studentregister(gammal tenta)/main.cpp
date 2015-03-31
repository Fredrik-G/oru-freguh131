#include <iostream>
#include <clocale>
#include "Student.h"
#include "StudentRegister.h"
using namespace std;

void Main3_1_2()
{
	Student s1;
	Student s2("Fredrik", "G");
	Student s3("Kalle", "Anka", 2005);

	s1.SetFirstName("Anders");
	s1.SetSecondName("And");
	cout << "s1= " << s1.GetFirstName() << " " << s1.GetSecondName() << " " << s1.GetYear() << endl;

	s2.Write();

	Student s4;
	s4.Read();
	s4.Write();


	system("pause");
}

void Main3_3()
{
	setlocale(LC_ALL, "swedish");
	Student s5,s6;
	
	//cout << "Skriv student på formen (förnamn,efternamn,inskrivningsår) ";
	//cin >> s5;

	istringstream iss("(Kalle,Anka,2005)");
	iss >> s5;
	cout << s5;

	cout << "\n\nSkriv in student på formen (förnamn,efternamn,inskrivningsår) ";
	cin >> s6;
	cout << s6;
	cout << "\n\n";
	system("pause");
}

void Main3_4()
{
	Student s2("Fredrik", "G");
	Student s3("Kalle", "Anka", 2005);
	
	StudentRegister sr;
	sr.Add(s2);
	sr.Add(s3);

	sr.ListStudents();
	//string s = sr.List();
	//cout << s << endl;
	//cout << s.size() << endl;
	//cout << s.length() << endl;
	system("pause");
}

void Main3_5()
{
	Student s2("Fredrik", "G");
	Student s3("Kalle", "Anka", 2005);
	
	StudentRegister sr;
	sr.Add(s2);
	sr.Add(s3);

	sr.WriteToFile();
	system("pause");
}

void Main3_6()
{
	StudentRegister sr;

	sr.ReadFromFile();


	sr.ListStudents();

//	string s = sr.List();
//	cout << s << endl;

	system("pause");
}

void Main4()
{
	StudentRegister sr;
	sr.Menu();
}

int main()
{

	//Main3_1_2();
	//Main3_3();
	//Main3_4();
	//Main3_5();
	//Main3_6();

	Main4();
	return 0;
}