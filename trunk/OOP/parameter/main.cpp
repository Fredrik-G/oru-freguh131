#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int main(int argc, char *argv[])
{
	for (int i = 0; i<argc; i++)
		cout << argv[i] << endl;


	//cout << argc << argv[2];

	system("pause");
	return 0;
}