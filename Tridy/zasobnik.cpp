/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   - Tridy
*     - Zasobnik
*
*	- [ ] Deklarujte třídu reprezetující zásobník s následujícími funkcemi:
*	  - konstruktor s kapacitou zásobníku,
*	  - funkci pro vložení nového prvku (push),
*	  - funkci která vrátí hodnotu posledního prvku a odebere ho ze zásobníku (pop).
*
*/

#include <iostream>
#include <cmath>

#define STACK_MAX 10


class Zasobnik
{
private:
	int z[STACK_MAX];
	int size;
public:
	Zasobnik()
	{
		this->size = 0;
	}
	//~Zasobnik();
	int push(int var1)
	{
		if(size < STACK_MAX)
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

int main()
{
	Zasobnik stack;

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