#include "MultiMedia.h"
#include <clocale>
MultiMedia::MultiMedia()
{
}
MultiMedia::~MultiMedia()
{
}

ostream & operator<<(ostream &stream, MultiMedia &m2) //cout
{
	stream << "(" << m2.id << "," << m2.name << "," << m2.year << ")";
	//stream << m2.name;
	//stream << m2.year;
	return stream;
}

istream & operator>>(istream &stream, MultiMedia &m2) //cin
{
	char c;
	stream >> c; //Läser bort första tecknet, parantesen
	getline(stream, m2.id, ',');
	getline(stream, m2.name, ',');
	stream >> m2.year >> c;
	
	return stream;
}

bool operator==(MultiMedia  &lop, MultiMedia &rop)
{              //Tar två mutlimedia, left&right
	if ( lop.id == rop.id && lop.name == rop.name && lop.year == rop.year )
		return true;
	else
		return false;
}
bool operator<(MultiMedia &first, MultiMedia &last)
{
	return first.GetID() < last.GetID();
}

