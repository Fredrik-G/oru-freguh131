#include <iostream>
#include <string>
#include <deque>

#include "Statistics.h"
#include "wordCounter.h"

#include "../hr_time.h"
#include "../Watch.h"
using namespace std;

bool palindrom(string s)
{
	deque<char> queue;
	//aktuell första&sista bokstav
	char front, back;

	//lägg till alla bokstäver i strängen till kön
	for(auto i = 0; i<s.size(); i++)
		queue.push_front(s[i]);

	while(queue.size() >= 2)
	{
		front = queue.front();
		back = queue.back();
		
		//jämför om första och sista bokstäverna är lika
		//poppa sedan första&sista och jämför nästa par

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

void main3_3a()
{
	wordCounter words;
	words.readFile("nils_holgersson.txt");
	words.printMostFrequent(10);

}
void main3_3b1()
{//med hr_time.h
	wordCounter words;
	CStopWatch csw;
	csw.startTimer();

	words.readFile("nils_holgersson.txt");
	words.printMostFrequent(10);

	csw.stopTimer();
	cout<<"Exekveringstid med hr_time.h: "<<csw.getElapsedTime()<<endl;
}
void main3_3b2()
{//med watch.h
	wordCounter words;

	Course::Watch w;
	Course::milliseconds t1;
	Course::nanoseconds t2;
	w.restart();

	words.readFile("nils_holgersson.txt");
	words.printMostFrequent(10);

	t1 = w.elapsedMs();
	t2 =  w.elapsedNs();

	cout<<"Exekveringstid med watch.h: "<<t2.count()/1e9<<endl;
}
int main()
{
	//main3_1();
	//main3_2();

	//main3_3a
	main3_3b1();
	//main3_3b2();
	system("pause");
}
