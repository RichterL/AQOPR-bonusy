/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   Dědičnost a překývání virtuálních členských funkcí
*
*	- Vytvořte **konzolovou aplikaci** pro správu farmy zvířátek:
*   - Nejdříve vytvořte verzi s jednou farmou viz wireframe farma
*     - Přidání nového zvířátka do farmy
*     - Výpis indexu a jména všech zvířátek ve farmě
*     - Výpis detailu jednoho zvířátka dle indexu
*
*
*/
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
using namespace std;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
void clear() { system("CLS");}
#elif defined(__linux) || defined(__linux__)
void clear() {system("clear");}
#else
void clear() { 
	cout << "\n\n";
	for (int i=0;i<32;i==){cout << "_";}
	cout << "\n\n";
}
#endif

class Zviratko
{
private:
	string jmeno;
	string zvuk;
public:
	Zviratko(string jmeno, string zvuk) : jmeno(jmeno), zvuk(zvuk)
	{

	}	
	string vypis()
	{
		return "Jsem " + jmeno + " a delam " + zvuk + ".\n";
	}
	string getJmeno()
	{
		return jmeno;
	}
};

int main()
{
	vector<Zviratko*> zviratka;
	vector<Zviratko*> farma;

	int volba;
	clear();
	while(1)
	{
		bool vybrano_menu = false;
		while(vybrano_menu == false)
		{

			cout << "Vyberte moznost: \n 1. Vytvorit nove zviratko\n 2. Pridat zviratko do farmy\n 3. Vypsat vsechna zviratka ve farme\n 0. Konec" << endl;
			cin >> volba;

			clear();
			if (cin.fail())
			{
				cout << "Zadej 1-3 nebo 0 pro konec.\n" << endl;
				cin.clear();
				cin.ignore();
			} 
			else if (cin.good())
			{
				switch (volba)
				{
					case 1:
					{
						string jmeno;
						string zvuk;
						do 
						{
							cin.clear();cin.ignore();
							cout << "Zadej jmeno zviratka: ";
							cin >> jmeno;
						} while (!cin.good());
						do
						{
							cin.clear();cin.ignore();
							cout << "Zadej zvuk zviratka: ";
							cin >> zvuk;
						} while (!cin.good());
						
						zviratka.push_back(new Zviratko(jmeno,zvuk));
						clear();
						cout << "Zviratko bylo pridano.\n" << endl;
						break;
					}
					case 2:
					{
						if (zviratka.size() < 1)
						{
							cout << "Nejprve vytvor nejaka zviratka.\n" << endl;
							break;
						}
						int pridat;
						cout << "Vyber zviratko ktere pridame do farmy: \n" << endl;
						for (uint i=0; i<zviratka.size(); i++)
						{
							cout << i+1 << ". " << zviratka[i]->getJmeno() << endl; 
						}
						cin >> pridat;
						clear();
						farma.push_back(zviratka[pridat-1]);
						cout << "Zviratko " << farma[pridat-1]->getJmeno() << " pridano do farmy.\n" << endl;
						break;
					}
					case 3:
					{
						if (farma.size() < 1)
						{
							cout << "Nejprve do farmy pridej nejaka zviratka.\n" << endl;
							break;
						}
						bool navrat = false;
						int detail=0;
						while (navrat==false)
						{
							clear();
							
							
							if(detail!=0)
							{
								cout << farma[detail-1]->vypis() << "\n" << endl;	
							}
							cout << "Ve farme jsou nasledujici zviratka: \n" << endl;

							for (uint i=0; i<farma.size(); i++)
							{
								cout << i+1 << ". " << farma[i]->getJmeno() << endl; 
							}
							
							cout << "\n\nVyber zviratko, o kterem chces vedet vic nebo 0 pro navrat." << endl;
							cin >> detail;
							if (detail == 0)
							{
								navrat = true;
								clear();
							}							
						}
						break;
					}
					case 0:
					{
						cout << "Ukoncuji ..." << endl;
						return 0;
						break;
					}
					default:{
						cout << "Neplatne zadani, zkus to znovu: " << endl;
						cin.clear();
						cin.ignore();
						break;
					}


				}
			}
		}
	}

	return 0;
}