#include <iostream>
#include <clocale>
using namespace std;
int n = 10;
int RecStrLength(char str[])
{
	int len = 0;
	if (str[0] == '\0')
		return;
	else
		len = 1 + RecStrLength(str[n-1]);
}

int main()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");
	cout << ":::::::LÄNGD AV TECKENSTRÄNG:::::::\n";


	}
}