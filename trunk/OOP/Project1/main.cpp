#include <iostream>
#include <string>
#include <M:\Desktop\år2\OOP\Project1\Car.h>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "swedish");
	system("color 0a");
	Car bil1;
	Car bil2("Volvo", 1969, 1337);
	Car bil3 = Car("Saab", 2000, 15000);
	//bil1.brand = "asd"; går ej pga private, går att göra funktion i headerfil

	bil1.setBrand("Skoda"); 
	
	
	bil1.print();
	bil2.print();
	bil3.print();

	bil1.ReadFromConsole();
	bil1.WriteToConsole();


	system("pause");
	return 0;
}