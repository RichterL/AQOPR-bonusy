/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   C++ features
*
*	- [ ] Deklarujte třídu Student v namespace utb, kdy student bude mít jméno a příjmení a výsledky tří testů. Využijte std::cout a případně std::cin a třídu std::string. Dále:
*	  - členské proměnné budou skryté (private) a k proměnným přistupujte pomocí veřejných (public) členských funkcí,
*	  - vytvořte členskou funkci, která vrátí true, pokud student získal zápočet, to znamená že z každého ze tří testů získal alespoň 15 bodů,
*	  - vytvořte členskou funkci, která vrátí průměr bodů ze tří testů studenta,
*	  - definujte dynamické pole (std::vector) studentů a vložte do něj alespoň tři studenty,
*	  - vypište jméno a příjmení studenta, který získal nejvíce bodů,
*	  - vypište průměrný počet bodů všech studentů a vypište jméno a příjmení studenta, který má svůj průměr bodů nejbližší celkovému průměru bodů,
*	  - vypište jména a příjmení studentů, kteří získali zápočet,
*	  - seřaďte studenty dle získaných bodů vzestupně a vypište jména, příjmení a průměrné body všech seřazených studentů.
*
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#define POCET_TESTU 3

namespace utb
{
	class Student
	{
	private:
		std::string jmeno;
		std::string prijmeni;
		std::string celejmeno;
		int test[POCET_TESTU];
		float prumer;
		int max_test;
		int celkem;
	public:
		Student(std::string var1, std::string var2, int test1, int test2, int test3): jmeno(var1), prijmeni(var2), test{test1,test2,test3}
		{
			celejmeno = jmeno + " " + prijmeni;
			spocitejPrumer();
			celkem = test[0]+test[1]+test[2];
			if (test1>test2)
			{
				max_test = test1;
			}
			else
			{
				max_test = test2;
			}
			if (test3 > max_test) max_test = test3;

		};
		//~Student();
		bool zapocet()
		{
			bool passed=true;
			for(int i=0;i<POCET_TESTU;i++)
			{
				if(test[i] < 15) passed = false;
			}
			
			return passed;
		}
		void spocitejPrumer()
		{
			float avg=0;
			int sum=0;
			for (int i=0; i<POCET_TESTU; i++)
			{
				sum = sum+test[i];
			}
			avg = sum/(double)POCET_TESTU;

			prumer = avg;
			celkem = sum; 			
		}
		std::string vypisJmeno()
		{
			return celejmeno;
		}
		double avg() { return prumer; }
		int max() {return max_test;}
		int sum() {return celkem;}
	};
}

int main()
{
	std::cout << std::setprecision(4);

	std::vector<utb::Student> pole;
	pole.push_back(utb::Student("Jana", "Novakova", 5,10,15));
	pole.push_back(utb::Student("Josef", "Fousek", 30,20,35));
	pole.push_back(utb::Student("Radim", "Tlusty", 40,17,25));
	pole.push_back(utb::Student("Tomas", "Marny", 38,22,33));
	pole.push_back(utb::Student("Alena","Strnadova",28,5,17));
	pole.push_back(utb::Student("Borek","Stavitel",35,14,6));
	pole.push_back(utb::Student("Cyril","Kratky",22,48,29));
	pole.push_back(utb::Student("David","Hruby",41,32,25));


	utb::Student * nejvice_bodu_test;
	utb::Student * nejvice_bodu_celkem;
	float total_avg=0;
	int pocet_studentu = pole.size();

	for (int i=0; i<pocet_studentu; i++)
	{
		if ( (i == 0) || (pole[i].max() > nejvice_bodu_test->max() ) ) { nejvice_bodu_test = &pole[i];}
		if ( (i == 0) || (pole[i].sum() > nejvice_bodu_celkem->sum() ) ) { nejvice_bodu_celkem = &pole[i];}
		total_avg += pole[i].avg();
	}

	std::cout << "Nejvice bodu z jednoho testu ma student " << nejvice_bodu_test->vypisJmeno() << " a to " << nejvice_bodu_test->max() << std::endl;
	std::cout << "Nejvice bodu celkem ma student " << nejvice_bodu_celkem->vypisJmeno() << " a to " << nejvice_bodu_celkem->sum() << std::endl;


	double avg_na_studenta = total_avg/pocet_studentu;
	std::cout << "\nCelkovy prumer bodu vsech studentu je " << avg_na_studenta << "\n" << std::endl;

	double nejmensi_rozptyl = 0;
	double rozptyl;
	utb::Student * nejblize_prumeru;
	for (int i=0; i<pocet_studentu; i++)
	{
		rozptyl = sqrt( pow( ( avg_na_studenta - pole[i].avg() ),2 ) );
		if ( (i==0) || (rozptyl < nejmensi_rozptyl) )
		{
			nejmensi_rozptyl = rozptyl;
			nejblize_prumeru = &pole[i];
		} 
		std::cout << "Student " << i+1 << ": " << pole[i].vypisJmeno() << " ma prumer " << pole[i].avg() << " bodu." << std::endl;		
		
	}	

	std::cout << "\nNejblize celkovemu prumeru je student " << nejblize_prumeru->vypisJmeno()  << "\n" << std::endl;

	for (int i=0;i<pocet_studentu;i++) 
	{
		if (pole[i].zapocet()) std::cout << pole[i].vypisJmeno() << " ziskal(a) zapocet." << std::endl;
	}

	std::cout << std::endl;
	

	bool swapped = true;
	utb::Student tmp("","",0,0,0);

	while(swapped)
	{	
		swapped = false;	
		for (int i=0; i<pocet_studentu-1; i++)
		{
			if (pole[i].sum() > pole[i+1].sum()) 
			{
				swapped = true;
				tmp = pole[i];
				pole[i] = pole[i+1];
				pole[i+1] = tmp;
			}
		}
	}

	for (int i=0; i<pocet_studentu; i++)
	{
		 
		std::cout << "Student " << i+1 << ": " << pole[i].vypisJmeno() << " ma prumer " << pole[i].avg() << " bodu." << std::endl;		
		
	}
	

	
	return 0;
}
