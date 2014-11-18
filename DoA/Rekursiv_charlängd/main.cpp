#include <iostream>
#include <clocale>
using namespace std;

int RecStrLength(char *str)
{
	int len = 0;
	if (str[0] == '\0')
		return 0;
	else
		len = 1 + RecStrLength(str+1);
	return len;
}

int main()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");
	cout << ":::::::LÄNGD AV TECKENSTRÄNG:::::::\n";

	char word[20];

	while (word[0] != 'q')
	{
		cout << "Skriv ord du vill beräkna längden av. Avsluta med q: ";
		cin >> word;
		if (word[0] != 'q')
			cout << "Antal tecken: " << RecStrLength(word) << endl;
	}
}