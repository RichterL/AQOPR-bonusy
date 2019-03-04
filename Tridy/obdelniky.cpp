/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   - Tridy
*     - Obdelniky
*   
*   Deklarujte třídu reprezentující obdelník s následujícími podrobnostmi:
*   vytvořte konstruktor s délkou a šírkou obdelníka,
*	vytvořte členské funkce pro výpočet obsahu a obvodu,
*	dále definujte pole obdelníků a vytvořte kód, který vypíše rozměry největšího obdelníku v poli.
*
*/

#include <iostream>

using namespace std;

class Obdelnik
{
private:
	int a;
	int b;
public:
	Obdelnik()
	{
		a=0;
		b=0;
	}
	void set(int var1, int var2)
	{
		this->a = var1;
		this->b = var2;
	}
	int obsah()
	{
		return a*b;
	}
	int obvod()
	{
		return 2*(a+b);
	}	
};

// alternativni zapis s inicializaci
class ObdelnikALT
{
private:
	int a;
	int b;
public:
	ObdelnikALT(int var1, int var2)
	{
		this->a = var1;
		this->b = var2;
	}
	int obsah()
	{
		return a*b;
	}
	int obvod()
	{
		return 2*(a+b);
	}
};

int main()
{
	const int pocet = 5;
	
	// definovani pole objektu bez inicializace a nastaveni promennych
	Obdelnik pole[pocet];
	int x; int y;
	srand(time(0));
	for (int i=0; i<pocet; i++)
	{
		x = 1 + rand() % 8; // nahodne cislo z rozsahu 1-8
		y = 1 + rand() % 8;
		pole[i].set(x,y);
	}

	// definovani pole objektu a inicializace s parametry
	ObdelnikALT poleALT[pocet] = {
		ObdelnikALT(2,5),
		ObdelnikALT(2,3),
		ObdelnikALT(4,6),
		ObdelnikALT(3,4),
		ObdelnikALT(1,5)
	};
	

	Obdelnik nejvetsi;
	ObdelnikALT nejvetsiALT(0,0);
	for (int i=0; i<pocet; i++)
	{
		if ( (pole[i].obsah() > nejvetsi.obsah()) || i==0 ) nejvetsi = pole[i];
		// hledani nejvetsiho obdelniku z prvniho pristupu

		if ( (poleALT[i].obsah() > nejvetsiALT.obsah()) || i==0 ) nejvetsiALT = poleALT[i];
		// hledani nejvetsiho obdelniku z alternativniho pristupu
	}
	cout << "Obsah nejvetsiho obdelniku je " << nejvetsi.obsah() << endl;
	cout << "Obsah nejvetsiho alternativniho obdelniku je " << nejvetsiALT.obsah() << endl;
	return 0;
}