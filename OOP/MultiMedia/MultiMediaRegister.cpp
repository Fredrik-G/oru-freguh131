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

	if( !val.empty() ) //Ritar ut en tom rad varje gång menyn ritas ut, förutom första gången programmet körs.
	cout << endl;

	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n";
	cout << "¤     Välkommen till MultiMedia-registret!       ¤\n";
	cout << "¤	Vad vill du göra?                        ¤\n";
	cout << "¤	 1: Lägg till multimedia                 ¤\n";
	cout << "¤	 2: Ta bort en produkt                   ¤\n";
	cout << "¤	 3: Visa alla produkter i registret      ¤\n";
	cout << "¤	 4: Sök efter en produkt                 ¤\n";
	cout << "¤	 5: Sortera produkterna efter ID         ¤\n";
	cout << "¤	 6: Skriv alla produkter till en fil     ¤\n";
	cout << "¤	 7: Läs in produkter från en fil         ¤\n";
	cout << "¤	 Q: Avsluta programmet                   ¤\n";
	cout << "¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n";
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
	cout << "       Ange på form (id,namn,år): ";
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
		cout << "ID måste vara unikt";
	else
		p->push_back(m);
}

void MultiMediaRegister::Delete()
{
	MMI it;
	string s;
	cout << "       Ange id på den produkt du vill ta bort: ";
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
	{//it tilldelas p[0] först och ökar tills sista elementet.
		cout << *it << "\n";
	}
}

void MultiMediaRegister::Search()
{
	MMI it;
	string s;
	bool klart = false;
	
	cout << "       Vill du söka efter id eller namn på produkten? ";
	cin >> s;
	while( !klart )
	{
	if (s == "id" )
	{
		s.clear();
		cout << "        Ange id på den produkt du vill visa: ";
		cin >> s;
		
		for (it = p->begin(); it < p->end(); it++)
		{
			if ( s.compare((*it).GetID()) == 0 )//Compare returnerar 0 om strängarna är lika
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
		cout << "        Ange namn på den produkt du vill visa: ";
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
		cout << "Ett fel uppstod. Välj alternativ med 'namn' eller 'id': ";
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
	cout << "       Vad vill du döpa filen till? ";
	cin >> s;

	//Detta lägger till .txt om användaren inte skrev det.
	size_t filtyp = s.find(s2);
	//Söker igenom strängen s och letar efter s2
	//Returnerar positionen om strängen hittas.
	if (filtyp == string::npos)
		//npos = no position, alltså strängen hittades inte.
		s = s+s2;

	f.open(s);

	if ( !f.good() )
	{
		cout << "Filen " << s << "går ej att öppna.\n";
		return;
	}
	else
	{
		cout << "Filen " << s << " skapades utan några problem.\n";
	}
	for (it = p->begin(); it < p->end(); it++)
	{
		f << *it << "\n"; //Skriver ut ett objekt/multimedia följt av en ny rad
	}

	f.close();
}

void MultiMediaRegister::ReadFromFile()
{
	ifstream f;
	MultiMedia produkt;
	MMI it;

	string s,s2 = ".txt";
	cout << "       Vilken fil vill du öppna? Skriv 'list' om du vill se aktuella filer: ";
	cin >> s;

	if ( s == "list" )
	{
		system("dir /B *.txt");//Vanligt windows-kommando som visar alla .txt-filer i programkatalogen.
		cout << "       Vilken fil vill du öppna?: ";
		cin >> s; 
	}

	size_t filtyp = s.find(s2);
	if (filtyp == string::npos)
		s = s+s2;

	f.open(s);

	if ( !f.good() )
	{
		cout << "Filen " << s << " går ej att öppna\n";
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
				cout << "ID måste vara unikt! Hittade flera ID=" << s;
			else
			{
				p->push_back(produkt);
			}
		}
	}

	f.close();
}

