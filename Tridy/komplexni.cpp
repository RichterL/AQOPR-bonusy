/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   - Tridy
*     - Komplexni cisla
* 
*	- [ ] Deklarujte třídu reprezentující komplexní číslo s následujícími podrobnostmi:
*	  - členské proměnné (reálná a imaginární část) budou private,
*	  - vytvořte konstruktor s reálnou i imaginární složkou,
*	  - vytvořte členskou funkci, která vrátí absolutní hodnotu komplexního čísla,
*	  - definujte pole komplexních čísel na zásobníku,
*	  - najděte komplexní číslo s největší absolutní hodnotou a vypište jeho komplexní a reálnou část.
*/

#include <iostream>
#include <cmath>


class Complex
{
private:
	int real;
	int imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	void set(int r, int i)
	{
		this->real = r;
		this->imag = i;
	}
	double abs()
	{
		return sqrt(pow(real,2)+pow(imag,2)) ;
	}
	int getR()
	{
		return real;
	}
	int getI()
	{
		return imag;
	}
};

int main()
{
	const int pocet = 5;
	srand(time(0));
	int randMin = -10;
	int randMax = 10;
	int randRange = sqrt(pow(randMin,2))+sqrt(pow(randMax,2));
	Complex pole[5];

	for (int i = 0; i < pocet; ++i)
	{
		int x = randMin + rand() % randRange;
		int y = randMin + rand() % randRange;

		pole[i].set(x,y);
	}	
	

	Complex nejvetsi;
	for (int i = 0; i < pocet; ++i)
	{
		if (pole[i].abs() > nejvetsi.abs() || i==0) nejvetsi = pole[i];
		
	}

	std::cout << "Nejvetsi absolutni hodnota je " << nejvetsi.abs() << " a to pro cislo s komplexni casti = " << nejvetsi.getR() << " a imaginarni casti = " << nejvetsi.getI() << std::endl;

	return 0;
}