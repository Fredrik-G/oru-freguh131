#include <iostream>
#include <clocale>
using namespace std;

int Palindrom(char word[], int s, int e)
{
	if (s >= e)
		return 1;
	else if (word[s] != word[e])
		return 0;

	Palindrom(word, s+1, e-1);
		
}

int main()
{
	char word[20];
	int word_len;

	setlocale(LC_ALL, "swedish");
	system("color 1f");
	cout << ":::::::PALINDROMTEST:::::::\n";

	while (word[0] != 'q')
	{
		cout << "Skriv ord du vill testa. Avsluta med q: ";
		cin >> word;

		for (int i = 0; i < 20; i++)
		{
			if (word[i] == '\0')
				word_len = i - 1;
		}

		if (Palindrom(word, 0, word_len))
			cout << "   Ordet " << word << " är en palindrom!\n\n";
		else
			cout << "   Ordet " << word << " är inte en palindrom.\n\n";

	}
}