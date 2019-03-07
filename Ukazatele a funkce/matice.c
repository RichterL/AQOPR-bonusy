/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   Ukazatele a funkce
*
*	- [ ] vytvořte program pro součet a násobení matic s proměnnými rozměry s využitím pole ukazatelů a alokací paměti na haldě pomocí funkce malloc,
*
*/

// scitani  A(a ij)m.n + B(b ij)p.q = C(c ij)m.n // p=m, q=n
// nasobeni A(a ij)m.n x B(b jk)p.q = C(c ik)m.q // p=n, q

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));


	// scitani


	int **A, **B, **C, **D;
	int m, n, p, q, i, j, k;

	m = 3; // radky A
	n = 3; // sloupce A

	p = 3; // radky B
	q = 3; // sloupce B

	

	// alokovani pameti pro radky matic
	A = (int **) malloc(sizeof(int *)*m);
	B = (int **) malloc(sizeof(int *)*p);
	C = (int **) malloc(sizeof(int *)*m);
	D = (int **) malloc(sizeof(int *)*m);

	// alokovani pameti pro sloupce matic
	for (i=0; i<m; i++)
	{
		A[i] = (int *)malloc(sizeof(int)*n);
		C[i] = (int *)malloc(sizeof(int)*n);	
		D[i] = (int *)malloc(sizeof(int)*q);	
		
	}
	for (i=0;i<p;i++)
	{
		B[i] = (int *)malloc(sizeof(int)*q);	
	}
	
	
	for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				A[i][j] = rand() % 10;
				B[i][j] = rand() % 10;				
			}
		}

	if ( (m != p) && (n != q) ) 
	{
		printf("Tyto matice nelze secist!\n");
	}
	else
	{

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				A[i][j] = rand() % 10;
				B[i][j] = rand() % 10;
				C[i][j] = A[i][j]+B[i][j];
			}
		}



		// vypis A+B=C
		for (i=0;i<m;i++)
		{
			printf("|");
			for (j=0;j<n;j++)
			{
				printf("%2d ", A[i][j]);
			}

			printf("|");
			
			if (i == m/2) 
			{printf(" + ");}
			else{printf("   ");}
			
			printf("|");
			for (j=0;j<n;j++)
			{
				printf("%2d ", B[i][j]);
			}		
			printf("|");
			
			if (i == m/2) 
			{printf(" = ");}
			else{printf("   ");}
			
			printf("|");
			for (j=0;j<n;j++)
			{
				printf("%2d ", C[i][j]);
			}		
			printf("|");
			printf("\n");
		}
		printf("\n");
	}

	// nasobeni

	int sum=0;
	if (p != n)
	{
		printf("Tyto matice nelze nasobit!\n");
	}
	else
	{
		for (i=0;i<m;i++)
		{
			for (j=0;j<q;j++)
			{
				D[i][j]=0;
				for (int k=0;k<q;k++)
				{
					D[i][j] += A[i][k]*B[k][j];
				}
			}
		}	
		

/*
*	 WORK IN PROGRESS 		
*/



		// vypis A*B=C

/*
		int printrows = m;
		



		if (p>m) printrows = p;
		for (i=0;i<printrows;i++)
		{
			printf("|");
			for (j=0;j<n;j++)
			{
				
				if (i<2) {printf("%2d ", A[i][j]);} else {printf("   ");}
			}

			printf("|");
			
			if (i == m/2) 
			{printf(" * ");}
			else{printf("   ");}
			
			printf("|");
			for (j=0;j<q;j++)
			{
				printf("%2d ", B[i][j]);
			}		
			printf("|");
			
			if (i == m/2) 
			{printf(" = ");}
			else{printf("   ");}
			
			printf("|");
			for (j=0;j<q;j++)
			{
				if (i<2) {printf("%3d ", D[i][j]);} else {printf("    ");}
			}		
			printf("|");
			printf("\n");
		}
*/
	}


	

	


	return 0;
}