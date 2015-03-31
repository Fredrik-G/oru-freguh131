#include <iostream>
#include <string>
#include <clocale>

using namespace std;

void SWAP(float *ptr_x, float *ptr_y);
void SWAP(float &x, float &y);
void SWAP(string &x, string &y);

int main(void)
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");

	float tal1=3.14, tal2=13.37;
	string text1, text2;
	cout << "Tal1=" << tal1 << "\t" << "Tal2=" << tal2 << "\n";

	SWAP(tal1, tal2);
	cout << "Efter swap:\nTal1=" << tal1 << "\t" << "Tal2=" << tal2 << "\n";
	

	SWAP(&tal2, &tal1);
	cout << "Efter swap igen:\nTal1=" << tal1 << "\t" << "Tal2=" << tal2 << "\n";
	
	string a = "Hello", b = "Good bye";
	cout << "\n\nA=" << a << "\t" << "B=" << b << "\n";
	
	SWAP(a, b);
	cout << "Efter swap:\nA=" << a << "\t" << "B=" << b << "\n";
	

	cout << "\n\nSkriv en textsträng:\n";
	cin >> text1;
	cout << "En till:\n";
	cin >> text2;
	

	SWAP(text1, text2);
	cout << "\nDet här skrev du, fast tvärtom:\n" << text1 << "\t" << text2 << "\n\n\n";
	system("pause");

	return 0;
}

void SWAP(string &x, string &y)
{
	string temp = x;
	x = y;
	y = temp;
}

void SWAP(float *ptr_x, float *ptr_y)
{
	float temp = *ptr_x;
	*ptr_x = *ptr_y;
	*ptr_y = temp;
}

void SWAP(float &x, float &y)
{
	float temp = x;
	x = y;
	y = temp;
}