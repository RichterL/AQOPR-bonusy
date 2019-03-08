/*
*   AQOPR 2019 / Lukas Richter
*   BONUSOVE PRIKLADY
*   Dědičnost
*
*	- Navrhněte třídy pro automobilové součástky s použitím dědičnosti, zvolte minimálně 3 součástky a 
*	kód který by měli společné vložte do rodičovské třídy. Navrhněte dvě třídy pro automobilové součástky pro demonstraci kompozice.
*
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Soucastka
{
protected:
	string nazev;
	string vyrobce;
	double prodejni_cena;
	double nakupni_cena;
	int skladem;
	int baleni;
public:
	Soucastka(string nazev, string vyrobce, double prodejni_cena, double nakupni_cena, int skladem, int baleni) : nazev(nazev), vyrobce(vyrobce), prodejni_cena(prodejni_cena), nakupni_cena(nakupni_cena), skladem(skladem), baleni(baleni)
	{

	}
	int baleni_skladem()
	{
		return skladem / baleni; // schvalne pouzivam int, aby se zaokrouhlilo na nejblizsi cele cislo smerem DOLU
	}
	
};

class Rozmer
{
protected:
	double delka;
	double sirka;
	double vyska;
public:
	Rozmer(double delka, double sirka, double vyska) : delka(delka), sirka(sirka), vyska(vyska)
	{
	};
};

class Pneumatika : public Soucastka
{
private:
	int sirka;
	int profil;
	int prumer;
	char[1] index_rychlosti;
	int index_nosnosti;
	bool letni;
	bool zimni;

public:
	Pneumatika(string vyrobce, string nazev, double prodejni_cena, double nakupni_cena, int skladem, int baleni, int sirka, int profil, int prumer, char[1] index_rychlosti, int index_nosnosti, bool letni, bool zimni) : Soucastka(string nazev, string vyrobce, double prodejni_cena, double nakupni_cena, int skladem, int baleni), sirka(sirka), profil(profil), prumer(prumer), index_rychlosti(index_rychlosti), index_nosnosti(index_nosnosti), letni(letni), zimni(zimni) 
	{
	}
	
	
};

class BrzdovyKotouc : public Soucastka
{
private:
	int prumer;
	int pocet_der;
	bool predni;
	bool zadni;
	bool vetrany;
public:
	BrzdovyKotouc(string vyrobce, string nazev, double prodejni_cena, double nakupni_cena, int skladem, int baleni, int prumer, int pocet_der, bool predni, bool zadni, bool vetrany) : Soucastka(string nazev, string vyrobce, double prodejni_cena, double nakupni_cena, int skladem, int baleni), prumer(prumer), pocet_der(pocet_der), predni(predni), zadni(zadni), vetrany(vetrany)
	{
	}
	
	
};

class Filtr_vzduchovy : public Soucastka
{
private:
	Rozmer rozmery
	
public:
	Filtr_vzduchovy(Rozmer rozmery, string vyrobce, string nazev, double prodejni_cena, double nakupni_cena, int skladem, int baleni) : rozmer(rozmery), Soucastka(string nazev, string vyrobce, double prodejni_cena, double nakupni_cena, int skladem, int baleni)
	{
	}
	
	
};

class Baterie : public Soucastka
{
private:
	Rozmer rozmery;
	int kapacita;
	int napeti;
public:
	Baterie(Rozmer rozmery, string vyrobce, string nazev, double prodejni_cena, double nakupni_cena, int skladem, int baleni, int kapacita, int napeti) : rozmery(rozmery), Soucastka(string nazev, string vyrobce, double prodejni_cena, double nakupni_cena, int skladem, int baleni), kapacita(kapacita), napeti(napeti)
};



int main(void)
{
	
	return 0;
}