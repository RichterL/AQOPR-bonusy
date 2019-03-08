/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   Dědičnost a překývání virtuálních členských funkcí
*
*	- [ ] Vytvořte **konzolovou aplikaci** pro správu geometrických útvaru viz. wireframe
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


class Utvar
{
protected:
	int x;
	string jmeno;
public:
	Utvar(int x) : x(x)
	{

	}
	virtual ~Utvar(){}
	virtual double obsah()
	{
		return 0;
	}
	int getX()
	{
		return x;
	}
	virtual void vypis(){}
};
class Kruh : public Utvar
{
public: 
	Kruh(int r) : Utvar(r)
	{
		this->jmeno = "Kruh";	
	}
	double obsah() override
	{
		double S = 3.14 * this->x * this->x;
		return S; 
	}
	void vypis() override
	{
		cout << "Kruh s polomerem " << this->x << endl;
	}
	int polomer(){return x;}
};
class Ctverec : public Utvar
{
public: 
	Ctverec(int a) : Utvar(a)
	{
		this->jmeno = "Ctverec";
	}
	double obsah() override
	{
		return ( this->x * this->x); 
	}
	void vypis() override
	{
		cout << "Ctverec se stranou " << this->x << endl;
	}
};
class Trojuhlenik : public Utvar{
public:
	Trojuhlenik(int a) : Utvar(a) 
	{
		this->jmeno = "Trojuhlenik";
	}
	double obsah(){
		return this->x * this->x * (sqrt(3) / 4);
	}
	void vypis(){
		cout << "Trojuhelnik se stranou " << this->x << endl; 
	}
};
int main()
{
	vector<Utvar*> v;
	int volba;
	int utvar;
	clear();
	while(1)
	{
		bool vybrano_menu = false;
		while(vybrano_menu == false)
		{

			cout << "Vyberte moznost: \n 1. Pridat novy utvar\n 2. Vypsat vsechny utvary\n 3. Vypsat utvar s nejvetsim obsahem\n 0. Konec" << endl;
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
					case 1: // Pridat do seznamu novy objekt
					{	

						bool vybrano = false;
						while (vybrano == false)
						{
								
							cout << "Vyberte utvar ktery chcete pridat: \n 1. Kruh\n 2. Ctverec\n 3. Rovnostranny trojuhelnik\n 0. Navrat zpet do menu\n" << endl;
							vybrano_menu = true;
							
							int a = 0;
							cin >> utvar;

							clear();
							if (cin.fail())
							{
								cout << "Zadej 1-3 nebo 0 pro navrat do predchozi nabidky.\n" << endl;
								cin.clear();
								cin.ignore();								
							}
							else if (cin.good())
							{
								switch (utvar)
								{
									case 1: // vybral kruh
										vybrano = true;				
										cout << "Zadej polomer: ";
										cin >> a;
										v.push_back(new Kruh(a)); 
										break;
									case 2: // vybral ctverec
										vybrano = true;				
										cout << "Zadej stranu: ";
										cin >> a;
										v.push_back(new Ctverec(a)); 
										break;
									case 3: // vybral trojuhelnik
										vybrano = true;	
										cout << "Zadej stranu: ";
										cin >> a;
										v.push_back(new Trojuhlenik(a)); 
										break;
									case 0: // vybral zpet									
										cout << "zpet" << endl;
										vybrano = true;
										clear();
										break;

									default:

										cout << "Neplatne zadani, zkus to znovu: " << endl;
										cin.clear();
										cin.ignore();
										break;
								}
							}
						}
						break;
					}
					case 2: // Vypsat vsechny zadane objekty
					{						
						vybrano_menu = true;	
						if (v.size() == 0)
						{
							cout << "Nejprve musite pridat nejake utvary.\n" << endl;
						}				
						else
						{
							cout << "Vypisuji vsechny zadane utvary ... " << endl;
							for (uint i=0;i<v.size();i++)
							{
								v[i]->vypis();
								
							}	
						}
						
						break;
					}
					case 3: // vypsat objekt s nejvetsim obsahem						
					{
						vybrano_menu = true;
						if (v.size() == 0)
						{
							cout << "Nejprve musite pridat nejake utvary.\n" << endl;
						}
						else 
						{
							int nejvetsi = 0;
							for (uint i=0;i<v.size();i++)
							{
								if (v[i]->obsah() > v[nejvetsi]->obsah()) nejvetsi = i;														
							}
							cout << "Nejvetsi obsah ma "; v[nejvetsi]->vypis();
						}
						
						break;
					}	
					case 0:
						cout << "Ukoncuji ... " << endl;
						return 0;
						break;
					default:
						cout << "Neplatne zadani, zkus to znovu: " << endl;
						cin.clear();
						cin.ignore();
				}
			}
		}	
	}
	return 0;
}