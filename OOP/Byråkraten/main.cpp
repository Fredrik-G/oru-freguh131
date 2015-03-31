#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <ctime>

#include "Språkmaskin.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "swedish");
	string test = "Test";
	Språkmaskin spalt1(1),spalt2,spalt3,spalt4,spalt5;
	// <string> spalt1,spalt2;
	spalt1.SkrivOrd();
	

	return 0;
}