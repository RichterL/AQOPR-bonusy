/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   C++ features
*
*	- [x] Deklarujte třídu reprezetující zásobník obsahující konstruktor s kapacitou zásobníku, funkci pro vložení nového prvku (push) a funkci která vrátí hodnotu posledního prvku a odebere ho ze zásobníku (pop), a využijte následující vlastnosti C++:
*	  - třídu vložte do namespace,
*	  - data pro zásobník alokujte pomocí operátoru new a uvolněte pomocí operátoru delete,
*	  - Vyberte jednu z následujících implementací
*	  - kapacitu deklarujte jako konstantní členskou proměnnou a inicializujte v konstruktoru pomocí constructor inicializer list,
*	  - pro členské proměnné inicializované konstantami využíjte in class inicializaci,
*	  - vytvořte ukázkový konzolový program s využitím objektů std::cout a std::cin.
*
*/

#include <iostream>

namespace opr 
{
	class Zasobnik
	{
	private:
		const int max;
		int size;
		int* z;
		

	public:
		Zasobnik(int var1): max(var1), size(0), z(NULL)
		{
			z = new int[max];
		}
		~Zasobnik()
		{
			delete[] z;
		}
		int push(int var1)
		{
			if(size < max)
			{
				size++;	
				z[size-1] = var1;
						
				return size;
			}
			else
			{
				return -1;
			}
		} 
		int pop()
		{
			if(size > 0)
			{
				int val = z[size-1];
				this->size--;
				return val;	
			}
			else
			{
				return -1;
			}
		}

		int getTop()
		{
			return z[size-1];
		}
	};
}


int main()
{
	int kapacita;
	do {
		std::cout << "Zadejte kapacitu zasobniku (pocet prvku): ";
		std::cin >> kapacita;
		if (kapacita < 1) 
		{
			std::cout << "Kapacita zasobniku musi byt cele kladne nenulove cislo." << std::endl;
			std::cin.clear(); std::cin.ignore();
		}
		else
		{
			std::cout << "Vytvoren zasobnik s kapacitou " << kapacita << "\nTestuji ... " << std::endl;	
			break;

		}	
	} while(1);
	
	

	opr::Zasobnik stack(kapacita);

	for (int i = 2; i < 512; i=2*i)
	{		
		int pushed = stack.push(i);
		if (pushed != -1)
		{
			std::cout << "uspesne vlzena hodnota " << i << " na vrch zasobniku na indexu " << pushed-1 << std::endl;
		}
		else
		{
			std::cout << "CHYBA: stack overflow - zasobnik je jiz plny" << std::endl;
			return -1;
		}	
	}


	for (int i = 0; i < 7; ++i)
	{
		int popped = stack.pop();
		if (popped != -1)
		{
			std::cout << "Z vrcholu zasobniku vracena hodnota " << popped << " a byla odstranena." << std::endl;
		}
		else
		{
			std::cout << "CHYBA: stack underflow - zasobnik je jiz prazdny!" << std::endl;
			return -1;
		}	
	}
	return 0;
}