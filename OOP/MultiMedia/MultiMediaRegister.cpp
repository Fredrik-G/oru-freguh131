#include "MultiMediaRegister.h"
#include <clocale>
#include <algorithm>

	string val;
MultiMediaRegister::MultiMediaRegister(MMV *pekare)
{
	p = pekare;
	quit=0;
}


MultiMediaRegister::~MultiMediaRegister()
{
}

void MultiMediaRegister::meny()
{	
	setlocale(LC_ALL, "swedish");

	if( !val.empty() ) //Ritar ut en tom rad varje g幩g menyn ritas ut, f顤utom f顤sta g幩gen programmet k顤s.
	cout << endl;

	cout << "中中中中中中中中中中中中中中中中中中中中中中中中中\n";
	cout << "�     V鄟kommen till MultiMedia-registret!       么n";
	cout << "�	Vad vill du g顤a?                        么n";
	cout << "�	 1: L輍g till multimedia                 么n";
	cout << "�	 2: Ta bort en produkt                   么n";
	cout << "�	 3: Visa alla produkter i registret      么n";
	cout << "�	 4: S闥 efter en produkt                 么n";
	cout << "�	 5: Sortera produkterna efter ID         么n";
	cout << "�	 6: Skriv alla produkter till en fil     么n";
	cout << "�	 7: L酲 in produkter fr幩 en fil         么n";
	cout << "�	 Q: Avsluta programmet                   么n";
	cout << "中中中中中中中中中中中中中中中中中中中中中中中中中\n";
	cout << "      Ange alternativ: ";
	cin >> val;
	
	if (val == "1")
		Add();
	else if (val == "2")
		Delete();
	else if (val == "3")
		List();
	else if (val == "4")
		Search();
	else if (val == "5")
		Sort();
	else if (val == "6")
		WriteToFile();
	else if (val == "7")
		ReadFromFile();

	else if (val == "q" || val == "Q")
		quit=1;

	else 
	{	
		cout << "Ej korrekt alternativ.\n";
	}
}

void MultiMediaRegister::Add()
{
	MMI it;
	setlocale(LC_ALL, "swedish");
	MultiMedia m;
	cout << "       Ange p� form (id,namn,緳): ";
	cin >> m;

	//Kolla att angivna ID inte finns i tidigare produkter(id ska vara unikt)
	string s = m.GetID();
	bool hittad = false;
	
	for (it = p->begin(); it < p->end(); it++)
	{
		if ( s == (*it).GetID() )	
			hittad = true;
	}

	if (hittad)
		cout << "ID m廛te vara unikt";
	else
		p->push_back(m);
}

void MultiMediaRegister::Delete()
{
	MMI it;
	string s;
	cout << "       Ange id p� den produkt du vill ta bort: ";
	cin >> s;
	for (it = p->begin(); it < p->end(); it++)
	{
		if ( s.compare((*it).GetID()) == 0 )
		{
			p->erase(it,it+1);
			break;
		}
	}
}

void MultiMediaRegister::List()
{
MMI it;

	for (it = p->begin(); it < p->end(); it++)
	{//it tilldelas p[0] f顤st och 闥ar tills sista elementet.
		cout << *it << "\n";
	}
}

void MultiMediaRegister::Search()
{
	MMI it;
	string s;
	bool klart = false;
	
	cout << "       Vill du s闥a efter id eller namn p� produkten? ";
	cin >> s;
	while( !klart )
	{
	if (s == "id" )
	{
		s.clear();
		cout << "        Ange id p� den produkt du vill visa: ";
		cin >> s;
		
		for (it = p->begin(); it < p->end(); it++)
		{
			if ( s.compare((*it).GetID()) == 0 )//Compare returnerar 0 om str鄚garna 酺 lika
			{
				cout << *it << "\n";

			}
		}
	klart =  true;
	return;
	}
	else if ( s == "namn" )
	{
		s.clear();
		cout << "        Ange namn p� den produkt du vill visa: ";
		cin >> s;

		for (it = p->begin(); it < p->end(); it++)
		{
			if ( s.compare((*it).GetName()) == 0 )
			{
				cout << *it << "\n";

			}
		}
	klart =  true;
	return;
	}
	else 
		s.clear();
		cout << "Ett fel uppstod. V鄟j alternativ med 'namn' eller 'id': ";
		cin >> s;
	}
}

void MultiMediaRegister::Sort()
{
	sort( p->begin(), p->end() );
}


void MultiMediaRegister::WriteToFile()
{
	ofstream f;
	MMI it;

	string s,s2 = ".txt";
	cout << "       Vad vill du d鞿a filen till? ";
	cin >> s;

	//Detta l輍ger till .txt om anv鄚daren inte skrev det.
	size_t filtyp = s.find(s2);
	//S闥er igenom str鄚gen s och letar efter s2
	//Returnerar positionen om str鄚gen hittas.
	if (filtyp == string::npos)
		//npos = no position, allts� str鄚gen hittades inte.
		s = s+s2;

	f.open(s);

	if ( !f.good() )
	{
		cout << "Filen " << s << "g緳 ej att 鞿pna.\n";
		return;
	}
	else
	{
		cout << "Filen " << s << " skapades utan n嶓ra problem.\n";
	}
	for (it = p->begin(); it < p->end(); it++)
	{
		f << *it << "\n"; //Skriver ut ett objekt/multimedia f闤jt av en ny rad
	}

	f.close();
}

void MultiMediaRegister::ReadFromFile()
{
	ifstream f;
	MultiMedia produkt;
	MMI it;

	string s,s2 = ".txt";
	cout << "       Vilken fil vill du 鞿pna? Skriv 'list' om du vill se aktuella filer: ";
	cin >> s;

	if ( s == "list" )
	{
		system("dir /B *.txt");//Vanligt windows-kommando som visar alla .txt-filer i programkatalogen.
		cout << "       Vilken fil vill du 鞿pna?: ";
		cin >> s; 
	}

	size_t filtyp = s.find(s2);
	if (filtyp == string::npos)
		s = s+s2;

	f.open(s);

	if ( !f.good() )
	{
		cout << "Filen " << s << " g緳 ej att 鞿pna\n";
		return;
	}


	//p->erase( p->begin(), p->end() );
	//Tar bort alla aktuella produkter.

	while ( !f.eof() )
	{
		f >> produkt;
		
		if ( !f.eof() )
		{
			//Kolla att m.GetID inte finns i tidigare produkter
			string s = produkt.GetID();
			bool hittad = false;
	
			for (it = p->begin(); it < p->end(); it++)
			{
				if ( s == (*it).GetID() )	
				hittad = true;
			}

			if (hittad)
				cout << "ID m廛te vara unikt! Hittade flera ID=" << s;
			else
			{
				p->push_back(produkt);
			}
		}
	}

	f.close();
}

