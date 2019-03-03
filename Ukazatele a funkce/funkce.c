/* 
*	Ukazatele a funkce:
* 	-vytvořte funkci, které předáte pole a ona vrátí největší prvek v poli,
* 	-vytvořte funkci, které předáte pole a ona vrátí strukturu obsahující nejmenší, největší a průměrný prvek,
* 	-vytvořte funkci, která prohodí hodnoty proměnných v poli (swap),
* 	-vytvořte program pro součet a násobení matic s proměnnými rozměry s využitím pole ukazatelů a alokací paměti na haldě pomocí funkce malloc,
* 	-vytvořte dynamické pole s pomocí struktury a funkce realloc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct str
{
	int min;
	int max;
	double avg;
};

int funkce1(int array[], int n)
{
	int max;
	for(int i=0;i<n;i++)
	{
		if(i==0) max=array[i];
		if (array[i]>max) max = array[i];
	}
	return max;
}

struct str funkce2(int array[], int n)
{
	struct str x;
	int sum=0;
	for (int i=0; i<n; i++)
	{
		if(i==0)
		{
			x.min = array[0]; x.max = array[0];
		}
		if (array[i] < x.min) x.min = array[i];
		if (array[i] > x.max) x.max = array[i];
		sum = sum + array[i];
	}
	x.avg = sum / n;
	return x;

}

void funkce3(int array[], int n)
{
	int tmp;
	for (int i=0; i<n/2; i++)
	{
		tmp = array[i];
		array[i] = array[n-i-1];
		array[n-i-1] = tmp;
	}	
	
}



int main()
{
	// inicializace pole nahodnych celych cisel
	
	srand(time(0));
	int pocet = 16;
	int rand_max = 256;
	int pole[pocet];
	for (int i=0;i<pocet;i++)
	{
		pole[i] = rand() % rand_max;
	}
	
	

	int nejvetsi = funkce1(pole,pocet);

	printf("nejvetsi prvek pole je %d\n", nejvetsi);


	struct str mujstruct = funkce2(pole,pocet);
	printf("nejvetsi prvek je %d, nejmensi je %d a prumerny je %.2f\n", mujstruct.max, mujstruct.min, mujstruct.avg); 


	printf("Puvodni pole :\n");
	for (int i=0; i<pocet; i++)
	{
		printf("%d ",pole[i] );
	}
	printf("\n");

	funkce3(pole,pocet);

	printf("Prohozene pole :\n");
	for (int i=0; i<pocet; i++)
	{
		printf("%d ",pole[i] );
	}
	printf("\n");	

	return 0;
}