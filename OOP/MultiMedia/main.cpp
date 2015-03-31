#include <iostream>
#include "MultiMedia.h"
#include "MultiMediaRegister.h"
#include <clocale>

using namespace std;
//Lägg till unika nycklar
int main()
{

	MMV r;
	MultiMediaRegister m(&r);

	system("title MultiMedia-register");
	system("color 1f");

	while ( ! m.Quit() )
	{
		m.meny();
	}

	return 0;
}