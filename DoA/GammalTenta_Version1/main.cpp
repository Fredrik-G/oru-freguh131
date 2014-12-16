#include <iostream>
#include <string>
#include <deque>

#include "Statistics.h"
using namespace std;

bool palindrom(string s)
{
	deque<char> queue;
	//aktuell f�rsta&sista bokstav
	char front, back;

	//l�gg till alla bokst�ver i str�ngen till k�n
	for(auto i = 0; i<s.size(); i++)
		queue.push_front(s[i]);

	while(queue.size() >= 2)
	{
		front = queue.front();
		back = queue.back();
		
		//j�mf�r om f�rsta och sista bokst�verna �r lika
		//poppa sedan f�rsta&sista och j�mf�r n�sta par

		if(front != back)
			//inte palindrom
			return false;

		if(queue.size() >= 2)
		{
			queue.pop_front();
			queue.pop_back();
		}
	}
	return true;
}
bool RekursivPalindrom(char word[], int s, int e)
{
	if (s >= e)
		return true;
	else if (word[s] != word[e])
		return false;

	RekursivPalindrom(word, s+1, e-1);
}

void main3_1()
{
	cout<<RekursivPalindrom("trollort", 0 , 7)<<endl;
	cout<<RekursivPalindrom("asd", 0 , 2)<<endl;

	cout<<endl<<palindrom("ajabaja")<<endl;
}
void main3_2()
{
	Statistics asd;
	asd.readFile("salary.txt");
	cout<<asd.calculate_mean()<<endl;
	cout<<asd.calculate_median()<<endl;
}



int main()
{
	//main3_1();
	main3_2();


	system("pause");
}
